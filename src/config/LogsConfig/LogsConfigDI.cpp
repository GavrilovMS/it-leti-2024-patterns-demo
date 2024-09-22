#include <config/LogsConfig/LogsConfigDI.h>

namespace config
{
	LogsConfigDI::LogsConfigDI()
	: ConfigDIBase { DEFAULT_LOGS_CONFIG_PATH, std::make_shared<DEFAULT_LOGS_CONFIG_READER>(DEFAULT_LOGS_CONFIG_PATH) }
	{ }

	const bool LogsConfigDI::LogsEnabled() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_lLogsEnabled;
	}

	const std::string & LogsConfigDI::LogsLevel() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_sLogsLevel;
	}

	const std::string & LogsConfigDI::LogsPath() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_sLogsFilePath;
	}

	const std::string & LogsConfigDI::LogsPattern() const
	{
		std::shared_lock lk(m_mtx);
		return m_pData->m_sLogsPattern;
	}

} // namespace config
