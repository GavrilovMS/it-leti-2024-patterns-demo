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

		if (jConfig.HasMember("general") && jConfig["general"].IsObject())
		{
			const auto & jGeneral = jConfig["general"].GetObject();

			if (jGeneral.HasMember("enable") && jGeneral["enable"].IsBool())
			{
				data.m_general.m_lEnabled = jGeneral["enable"].GetBool();
			}

			if (!data.m_general.m_lEnabled)
			{
				return true;
			}

			if (jGeneral.HasMember("level") && jGeneral["level"].IsString())
			{
				data.m_general.m_sLevel = jGeneral["level"].GetString();
			}

			if (jGeneral.HasMember("path") && jGeneral["path"].IsString())
			{
				data.m_general.m_sFilePath = jGeneral["path"].GetString();
			}

			if (jGeneral.HasMember("pattern") && jGeneral["pattern"].IsString())
			{
				data.m_general.m_sPattern = jGeneral["pattern"].GetString();
			}
		}

		if (jConfig.HasMember("logs") && jConfig["logs"].IsArray())
		{
			const auto & jLogs = jConfig["logs"].GetArray();
			for (const auto & jLog : jLogs)
			{
				if (!jLog.IsObject())
				{
					continue;
				}
				LogsConfigData::loginfo_t info = data.m_general;

				if (jLog.HasMember("name") && jLog["name"].IsString())
				{
					info.m_sName = jLog["name"].GetString();
				}

				if (jLog.HasMember("enable") && jLog["enable"].IsBool())
				{
					data.m_general.m_lEnabled = jLog["enable"].GetBool();
				}

				if (!info.m_lEnabled)
				{
					return true;
				}

				if (jLog.HasMember("level") && jLog["level"].IsString())
				{
					info.m_sLevel = jLog["level"].GetString();
				}

				if (jLog.HasMember("path") && jLog["path"].IsString())
				{
					info.m_sFilePath = jLog["path"].GetString();
				}

				if (jLog.HasMember("pattern") && jLog["pattern"].IsString())
				{
					info.m_sPattern = jLog["pattern"].GetString();
				}

				data.m_logs.push_back(info);
			}
		}

		return true;
	}

} // namespace config
