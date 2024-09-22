#include <config/LogsConfig/LogsConfigData.h>

std::ostream & operator<< (std::ostream & os, const config::LogsConfigData & data)
{
	os << "enable: " << data.m_lLogsEnabled << std::endl;
	os << "level: " << data.m_sLogsLevel << std::endl;
	os << "path: " << data.m_sLogsFilePath << std::endl;
	os << "pattern: " << data.m_sLogsPattern << std::endl;

	return os;
}