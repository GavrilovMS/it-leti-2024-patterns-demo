#pragma once

#include <ostream>
#include <vector>

#include <config/ConfigDataBase.h>
#include <config/IFileConfigReader.h>

namespace config
{
	class LogsConfigData : public ConfigDataBase
	{
	public:
		FULLY_PTRABLE(LogsConfigData)

		static const constexpr bool DEFAULT_LOGS_ENABLED = true;
		static const constexpr char * DEFAULT_LOGS_LEVEL = "info";
		static const constexpr char * DEFAULT_LOGS_FILE_PATH = "logs";
		static const constexpr char * DEFAULT_LOGS_PATTERN = "%Y-%m-%d %H:%M:%S [%l] ";

	public:
		struct LogInfo
		{
			std::string m_sName;
			bool m_lEnabled { DEFAULT_LOGS_ENABLED };
			std::string m_sLevel { DEFAULT_LOGS_LEVEL };
			std::string m_sFilePath { DEFAULT_LOGS_FILE_PATH };
			std::string m_sPattern { DEFAULT_LOGS_PATTERN };
		};
		using loginfo_t = LogInfo;
		using loginfo_vec_t = std::vector<loginfo_t>;

		loginfo_t m_general { .m_sName = "general" };
		loginfo_vec_t m_logs;
	};
} // namespace config

std::ostream & operator<< (std::ostream & os, const config::LogsConfigData::LogInfo & info);
std::ostream & operator<< (std::ostream & os, const config::LogsConfigData & data);