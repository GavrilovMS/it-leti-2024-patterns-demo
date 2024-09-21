#pragma once

#include <mutex>
#include <string>

#include <config/ConfigDI/ConfigData.h>
#include <config/ConfigDI/JsonConfigReader.h>

#include <utils/Singleton.h>

namespace config
{
#ifndef DEFAULT_CONFIG_READER
	typedef JsonConfigReader DEFAULT_CONFIG_READER;
#endif

	class ConfigDI : public utils::Singleton<ConfigDI>
	{
	public:
		static const constexpr char * DEFAULT_CONFIG_FILE_PATH = "config/config.json";

		void Init(const std::string & sFilePath, IFileConfigReader::s_ptr_t pReader = nullptr);
		void Init(IFileConfigReader::s_ptr_t pReader = nullptr);

		bool Update();

	private:
		std::string m_sFilePath { DEFAULT_CONFIG_FILE_PATH };

		std::mutex m_mtx;
		ConfigData::u_ptr_t m_pData { std::make_unique<ConfigData>() };
		IFileConfigReader::s_ptr_t m_pReader { std::make_shared<DEFAULT_CONFIG_READER>(m_sFilePath) };
	};
} // namespace config
