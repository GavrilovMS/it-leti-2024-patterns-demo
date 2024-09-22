#pragma once

#include <config/ConfigDIBase.h>

#include <config/LogsConfig/LogsConfigData.h>
#include <config/LogsConfig/LogsJsonConfigReader.h>

#include <utils/Singleton.h>

namespace config
{
	class LogsConfigDI
	: public ConfigDIBase<LogsConfigData>
	, public utils::Singleton<LogsConfigDI>
	{
	public:
		static const constexpr char * DEFAULT_LOGS_CONFIG_PATH = "config/logs.json";
		using DEFAULT_LOGS_CONFIG_READER = LogsJsonConfigReader;

		LogsConfigDI();

	public:
		const bool Enabled() const;
		const std::string & GeneralLevel() const;
		const std::string & GeneralPath() const;
		const std::string & GeneralPattern() const;

		const LogsConfigData::loginfo_vec_t & Logs() const;
		const LogsConfigData::loginfo_t & GetInfoByName(const std::string & sName) const;
	};
} // namespace config
