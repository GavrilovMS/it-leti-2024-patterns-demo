#include <algorithm>

#include <config/LogsConfig/LogsConfigDI.h>

namespace config
{
	LogsConfigDI::LogsConfigDI()
	: ConfigDIBase { DEFAULT_LOGS_CONFIG_PATH, std::make_shared<DEFAULT_LOGS_CONFIG_READER>(DEFAULT_LOGS_CONFIG_PATH) }
	{ }

	const bool LogsConfigDI::Enabled() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_general.m_lEnabled;
	}

	const std::string & LogsConfigDI::GeneralLevel() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_general.m_sLevel;
	}

	const std::string & LogsConfigDI::GeneralPath() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_general.m_sFilePath;
	}

	const std::string & LogsConfigDI::GeneralPattern() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_general.m_sPattern;
	}

	const LogsConfigData::loginfo_vec_t & LogsConfigDI::Logs() const
	{
		return m_pData->m_logs;
	}

	const LogsConfigData::LogInfo & LogsConfigDI::GetInfoByName(const std::string & sName) const
	{
		std::shared_lock lk(m_mtx);
		auto it = std::find_if(m_pData->m_logs.begin(), m_pData->m_logs.end(), [&sName](const LogsConfigData::LogInfo & info) { return info.m_sName == sName; });
		if (it != m_pData->m_logs.end())
		{
			return *it;
		}
		else
		{
			return m_pData->m_general;
		}
	}

} // namespace config
