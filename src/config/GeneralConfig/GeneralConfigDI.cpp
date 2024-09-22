#include <config/GeneralConfig/GeneralConfigDI.h>

namespace config
{
	GeneralConfigDI::GeneralConfigDI()
	: ConfigDIBase { DEFAULT_GENERAL_CONFIG_PATH, std::make_shared<DEFAULT_GENERAL_CONFIG_READER>(DEFAULT_GENERAL_CONFIG_PATH) }
	{ }

	const std::string & GeneralConfigDI::Ip() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_sIpAddress;
	}

	const uint32_t & GeneralConfigDI::Port() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_nPort;
	}
} // namespace config
