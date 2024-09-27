#include <fstream>
#include <sstream>

#include <config/GeneralConfig/GeneralJsonConfigReader.h>
#include <config/GeneralConfig/GeneralConfigData.h>

#include <utils/Logs/LogsMacro.h>

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/istreamwrapper.h>

namespace config
{
	GeneralJsonConfigReader::GeneralJsonConfigReader(const std::string & sFilePath)
	: FileConfigReaderBase { sFilePath }
	{ }

	bool GeneralJsonConfigReader::Read(ConfigDataBase & baseData)
	{
		GeneralConfigData & data = dynamic_cast<GeneralConfigData &>(baseData);

		std::ifstream file(m_sFilePath);
		if (!file.is_open())
		{
			CONFIG_ERROR("Failed to open file: {}", m_sFilePath)
			return false;
		}

		rapidjson::IStreamWrapper isw(file);
		rapidjson::Document jConfig;
		if (jConfig.ParseStream(isw).HasParseError())
		{
			CONFIG_ERROR("Failed to parse file: {}. Error: {}", m_sFilePath, rapidjson::GetParseError_En(jConfig.GetParseError()))
			return false;
		}

		if (!jConfig.IsObject())
		{
			CONFIG_ERROR("Config value should be an object type")
			return false;
		}

		if (jConfig.HasMember("general") && jConfig["general"].IsObject())
		{
			const auto & jGeneral = jConfig["general"].GetObject();

			if (jGeneral.HasMember("ip") && jGeneral["ip"].IsString())
			{
				data.m_sIpAddress = jGeneral["ip"].GetString();
			}

			if (jGeneral.HasMember("port") && jGeneral["port"].IsUint())
			{
				data.m_nPort = jGeneral["port"].GetUint();
			}
		}

		return true;
	}

} // namespace config
