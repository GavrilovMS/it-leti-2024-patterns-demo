#pragma once

#include <sstream>
#include <memory>
#include <shared_mutex>

#include <spdlog/spdlog.h>

#include <config/IFileConfigReader.h>

namespace config
{
	template<typename DataT>
	class ConfigDIBase
	{
	public:
		virtual ~ConfigDIBase() = default;

		ConfigDIBase(const std::string & sFilePath, IFileConfigReader::s_ptr_t pReader)
		: m_sFilePath { sFilePath }
		, m_pReader { pReader }
		{ }

		void Init(const std::string & sFilePath, IFileConfigReader::s_ptr_t pReader = nullptr)
		{
			m_sFilePath = sFilePath;
			Init(pReader);
		}

		void Init(IFileConfigReader::s_ptr_t pReader = nullptr)
		{
			if (pReader)
			{
				m_pReader = pReader;
				m_pReader->SetFilePath(m_sFilePath);
			}
			if (!Update())
				spdlog::warn("Failed to init config. Use default values.");
			std::stringstream ssConfig;
			ssConfig << *m_pData;
			spdlog::info("{}:\n{}", Name(), ssConfig.str());
		}

		bool Update()
		{
			auto pNewData = std::make_unique<DataT>();
			if (pNewData->Load(m_pReader))
			{
				std::unique_lock lk(m_mtx);
				m_pData = std::move(pNewData);
				return true;
			}
			return false;
		}

		virtual const std::string & Name() const { return m_sFilePath; }

	protected:
		std::string m_sFilePath;
		mutable std::shared_mutex m_mtx;
		std::unique_ptr<DataT> m_pData { std::make_unique<DataT>() };
		IFileConfigReader::s_ptr_t m_pReader { nullptr };
	};
} // namespace config
