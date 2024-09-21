#pragma once

#include <memory>

#include <config/ConfigDI/defaults.h>
#include <config/IFileConfigReader.h>
namespace config
{
	class ConfigData
	: public ConfigLoadTraits
	, public std::enable_shared_from_this<ConfigData>
	{
	public:
		FULLY_PTRABLE(ConfigData)
		bool Load(IFileConfigReader::s_ptr_t pReader);
	
	public:
		// general
		std::string m_sIpAddress{defaults::DEFAULT_IP_ADDRESS};
		uint32_t m_nPort{defaults::DEFAULT_PORT};

		// logs
		std::string m_sLogsLevel{defaults::DEFAULT_LOGS_LEVEL};
		std::string m_sLogsFilePath{defaults::DEFAULT_LOGS_FILE_PATH};
		std::string m_sLogsPattern{defaults::DEFAULT_LOGS_PATTERN};
	};
} // namespace config
