#pragma once

#include <ostream>

#include <config/ConfigDataBase.h>
#include <config/IFileConfigReader.h>

namespace config
{
	class LogsConfigData : public ConfigDataBase
	{
	public:
		FULLY_PTRABLE(LogsConfigData)

		static constexpr const bool DEFAULT_LOGS_ENABLED = true;
		static constexpr const char * DEFAULT_LOGS_LEVEL = "info";
		static constexpr const char * DEFAULT_LOGS_FILE_PATH = "logs";
		static constexpr const char * DEFAULT_LOGS_PATTERN = "%Y-%m-%d %H:%M:%S [%l] ";

	public:
		bool m_lLogsEnabled { DEFAULT_LOGS_ENABLED };
		std::string m_sLogsLevel { DEFAULT_LOGS_LEVEL };
		std::string m_sLogsFilePath { DEFAULT_LOGS_FILE_PATH };
		std::string m_sLogsPattern { DEFAULT_LOGS_PATTERN };
	};
} // namespace config

std::ostream & operator<< (std::ostream & os, const config::LogsConfigData & data);