#include <utils/Logs/LogsManager.h>
#include <utils/Logs/LogsSettings.h>

#include <spdlog/sinks/basic_file_sink.h>

namespace utils
{
	void LogsManager::Init()
	{
		InitLog(CONFIG_LOG_NAME, CONFIG_LOG_PATH, CONFIG_LOG_PATTERN);
	}

	void LogsManager::InitLog(const std::string & sName, const std::string & sFile, const std::string & sPattern)
	{
		auto logger = spdlog::basic_logger_mt(sName, sFile);
		logger->set_pattern(sPattern);
		logger->set_level(spdlog::level::trace);
		m_loggers.insert({ sName, logger });
	}

	LogsManager::logger_s_ptr_t LogsManager::GetLogByName(const std::string & sName)
	{
		auto it = m_loggers.find(sName);
		if (it != m_loggers.end())
		{
			return it->second;
		}
		return spdlog::default_logger();
	}
} // namespace utils
