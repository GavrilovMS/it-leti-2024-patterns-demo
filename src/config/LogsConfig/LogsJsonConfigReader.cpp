#include <fstream>

#include <config/LogsConfig/LogsJsonConfigReader.h>
#include <config/LogsConfig/LogsConfigData.h>

#include <spdlog/spdlog.h>

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/istreamwrapper.h>

namespace config
{
	LogsJsonConfigReader::LogsJsonConfigReader(const std::string & sFilePath)
	: FileConfigReaderBase { sFilePath }
	{ }

	bool LogsJsonConfigReader::Read(ConfigDataBase & baseData)
	{
		LogsConfigData data;
		try
		{
			data = dynamic_cast<LogsConfigData &>(baseData);
		}
		catch (...)
		{
			return false;
		}

		std::ifstream file(m_sFilePath);
		if (!file.is_open())
		{
			spdlog::error("Failed to open file: {}", m_sFilePath);
			return false;
		}

		rapidjson::IStreamWrapper isw(file);
		rapidjson::Document jConfig;
		if (jConfig.ParseStream(isw).HasParseError())
		{
			spdlog::error("Failed to parse file: {}. Error: {}", m_sFilePath, rapidjson::GetParseError_En(jConfig.GetParseError()));
			return false;
		}

		if (!jConfig.IsObject())
		{
			spdlog::error("Config value should be an object type");
			return false;
		}

		if (jConfig.HasMember("logs") && jConfig["logs"].IsObject())
		{
			const auto & jLogs = jConfig["logs"].GetObject();

			if (jLogs.HasMember("enable") && jLogs["enable"].IsBool())
			{
				data.m_lLogsEnabled = jLogs["enable"].GetBool();
			}

			if (jLogs.HasMember("level") && jLogs["level"].IsString())
			{
				data.m_sLogsLevel = jLogs["level"].GetString();
			}

			if (jLogs.HasMember("path") && jLogs["path"].IsString())
			{
				data.m_sLogsFilePath = jLogs["path"].GetString();
			}

			if (jLogs.HasMember("pattern") && jLogs["pattern"].IsString())
			{
				data.m_sLogsPattern = jLogs["pattern"].GetString();
			}
		}

		return true;
	}

} // namespace config
