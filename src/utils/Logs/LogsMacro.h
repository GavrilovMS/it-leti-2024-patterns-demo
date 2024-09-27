#pragma once

#include <utils/Logs/LogsManager.h>
#include <utils/Logs/LogsSettings.h>

#define GET_LOGGER_BY_NAME(name) utils::LogsManager::Instance().GetLogByName(name).get()

#define CONFIG_TRACE(...) SPDLOG_LOGGER_TRACE(GET_LOGGER_BY_NAME(utils::CONFIG_LOG_NAME), __VA_ARGS__);
#define CONFIG_DEBUG(...) SPDLOG_LOGGER_DEBUG(GET_LOGGER_BY_NAME(utils::CONFIG_LOG_NAME), __VA_ARGS__);
#define CONFIG_INFO(...) SPDLOG_LOGGER_INFO(GET_LOGGER_BY_NAME(utils::CONFIG_LOG_NAME), __VA_ARGS__);
#define CONFIG_WARN(...) SPDLOG_LOGGER_WARN(GET_LOGGER_BY_NAME(utils::CONFIG_LOG_NAME), __VA_ARGS__);
#define CONFIG_ERROR(...) SPDLOG_LOGGER_ERROR(GET_LOGGER_BY_NAME(utils::CONFIG_LOG_NAME), __VA_ARGS__);
#define CONFIG_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(GET_LOGGER_BY_NAME(utils::CONFIG_LOG_NAME), __VA_ARGS__);

