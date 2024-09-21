#pragma once

#include <cstdlib>
#include <config/ConfigDI/JsonConfigReader.h>

namespace config
{
	namespace defaults
	{
		static const constexpr char * DEFAULT_CONFIG_FILE_PATH = "config/config.json";
#ifndef DEFAULT_CONFIG_READER
		typedef JsonConfigReader DEFAULT_CONFIG_READER;
#endif
		// general
		static const constexpr char * DEFAULT_IP_ADDRESS = "127.0.0.1";
		static const uint32_t DEFAULT_PORT = 8080;

		// logs
		static const bool DEFAULT_LOGS_ENABLED = true;
		static const constexpr char * DEFAULT_LOGS_FILE_PATH = "logs/callcenter.log";
		static const constexpr char * DEFAULT_LOGS_LEVEL = "info";
		static const constexpr char * DEFAULT_LOGS_PATTERN = "[%Y-%m-%d %H:%M:%S.%e] [%l] %v";

	} // namespace defaults
} // namespace config
