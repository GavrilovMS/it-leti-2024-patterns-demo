#include <fstream>

#include <config/ConfigDI/JsonConfigReader.h>
#include <config/ConfigDI/ConfigData.h>

#include <spdlog/spdlog.h>

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/istreamwrapper.h>

namespace config
{
	JsonConfigReader::JsonConfigReader(const std::string & sFilePath)
	: m_sFilePath { sFilePath }
	{ }

	bool JsonConfigReader::Read(ConfigLoadTraits::s_ptr_t pTraits)
	{
		auto pData = std::dynamic_pointer_cast<ConfigData>(pTraits);
		if (!pData)
			return false;

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

			if (jGeneral.HasMember("ip") && jGeneral["ip"].IsString())
			{
				pData->m_sIpAddress = jGeneral["ip"].GetString();
			}

			if (jGeneral.HasMember("port") && jGeneral["port"].IsUint())
			{
				pData->m_nPort = jGeneral["port"].GetUint();
			}
		}

		if (jConfig.HasMember("logs") && jConfig["logs"].IsObject())
		{
			const auto & jLogs = jConfig["logs"].GetObject();

			if (jLogs.HasMember("enable") && jLogs["enable"].IsBool())
			{
				pData->m_lLogsEnabled = jLogs["enable"].GetBool();
			}

			if (jLogs.HasMember("level") && jLogs["level"].IsString())
			{
				pData->m_sLogsLevel = jLogs["level"].GetString();
			}

			if (jLogs.HasMember("path") && jLogs["path"].IsString())
			{
				pData->m_sLogsFilePath = jLogs["path"].GetString();
			}

			if (jLogs.HasMember("pattern") && jLogs["pattern"].IsString())
			{
				pData->m_sLogsPattern = jLogs["pattern"].GetString();
			}
		}

		return true;
	}

	void JsonConfigReader::SetFilePath(const std::string & sFilePath)
	{
		m_sFilePath = sFilePath;
	}
} // namespace config
