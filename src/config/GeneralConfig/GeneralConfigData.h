#pragma once

#include <ostream>

#include <config/ConfigDataBase.h>
#include <config/IFileConfigReader.h>

namespace config
{
	class GeneralConfigData : public ConfigDataBase
	{
	public:
		FULLY_PTRABLE(GeneralConfigData)

		static constexpr const char * DEFAULT_IP_ADDRESS = "127.0.0.1";
		static constexpr uint32_t DEFAULT_PORT = 8080;

	public:
		std::string m_sIpAddress { DEFAULT_IP_ADDRESS };
		uint32_t m_nPort { DEFAULT_PORT };
	};
} // namespace config

std::ostream & operator<< (std::ostream & os, const config::GeneralConfigData & data);