#include <config/GeneralConfig/GeneralConfigData.h>

std::ostream& operator<<(std::ostream& os, const config::GeneralConfigData& data)
{
	os << "ip: " << data.m_sIpAddress << std::endl;
	os << "port: " << data.m_nPort << std::endl;

	return os;
}