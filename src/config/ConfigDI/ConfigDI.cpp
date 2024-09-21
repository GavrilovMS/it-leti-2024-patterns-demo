#include <sstream>

#include <config/ConfigDI/ConfigDI.h>

#include <spdlog/spdlog.h>

namespace config
{
	void ConfigDI::Init(const std::string & sFilePath, IFileConfigReader::s_ptr_t pReader)
	{
		m_sFilePath = sFilePath;
		Init(pReader);
	}

	void ConfigDI::Init(IFileConfigReader::s_ptr_t pReader)
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
		spdlog::info("Config:\n{}", ssConfig.str());
	}

	bool ConfigDI::Update()
	{
		auto pNewData = std::make_shared<ConfigData>();
		if (pNewData->Load(m_pReader))
		{
			std::unique_lock lk(m_mtx);
			m_pData = pNewData;
			return true;
		}
		return false;
	}

	const std::string & ConfigDI::Ip() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_sIpAddress;
	}

	const uint32_t & ConfigDI::Port() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_nPort;
	}

	const bool ConfigDI::LogsEnabled() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_lLogsEnabled;
	}

	const std::string & ConfigDI::LogsLevel() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_sLogsLevel;
	}

	const std::string & ConfigDI::LogsPath() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_sLogsFilePath;
	}

	const std::string & ConfigDI::LogsPattern() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_sLogsPattern;
	}

} // namespace config
