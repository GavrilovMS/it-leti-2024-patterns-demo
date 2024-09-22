#include <config/LogsConfig/LogsConfigData.h>

std::ostream & operator<< (std::ostream & os, const config::LogsConfigData::LogInfo & info)
{
	os << "name: " << info.m_sName << std::endl;
	os << "enable: " << info.m_lEnabled << std::endl;
	os << "level: " << info.m_sLevel << std::endl;
	os << "path: " << info.m_sFilePath << std::endl;
	os << "pattern: " << info.m_sPattern << std::endl;

	return os;
}

std::ostream & operator<< (std::ostream & os, const config::LogsConfigData & data)
{
	os << data.m_general;
	for (const auto & log : data.m_logs)
	{
		os << log;
	}
	return os;
}