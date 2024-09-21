#include <config/ConfigDI/ConfigData.h>

namespace config
{
	bool ConfigData::Load(IFileConfigReader::s_ptr_t pReader)
	{
		return pReader->Read(shared_from_this());
	}
} // namespace config

std::ostream& operator<<(std::ostream& os, const config::ConfigData& data)
{
	os << "general:" << std::endl;
	os << "ip: " << data.m_sIpAddress << std::endl;
	os << "port: " << data.m_nPort << std::endl;

	os << "logs:" << std::endl;
	os << "enable: " << data.m_lLogsEnabled << std::endl;
	os << "level: " << data.m_sLogsLevel << std::endl;
	os << "path: " << data.m_sLogsFilePath << std::endl;
	os << "pattern: " << data.m_sLogsPattern << std::endl;

	return os;
}