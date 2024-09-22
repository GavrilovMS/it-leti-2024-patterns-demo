#pragma once

#include <config/ConfigDIBase.h>

#include <config/GeneralConfig/GeneralConfigData.h>
#include <config/GeneralConfig/GeneralJsonConfigReader.h>

#include <utils/Singleton.h>

namespace config
{
	class GeneralConfigDI
	: public ConfigDIBase<GeneralConfigData>
	, public utils::Singleton<GeneralConfigDI>
	{
	public:
		static const constexpr char * DEFAULT_GENERAL_CONFIG_PATH = "config/general.json";
		using DEFAULT_GENERAL_CONFIG_READER = GeneralJsonConfigReader;

		GeneralConfigDI();

	public:
		const std::string & Ip() const;
		const uint32_t & Port() const;
	};
} // namespace config
