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
		const bool LogsEnabled() const;
		const std::string & LogsLevel() const;
		const std::string & LogsPath() const;
		const std::string & LogsPattern() const;
	};
} // namespace config
