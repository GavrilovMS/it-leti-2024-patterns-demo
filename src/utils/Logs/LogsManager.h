#pragma once

#include <map>
#include <memory>
#include <vector>

#include <utils/Singleton.h>

#include <spdlog/spdlog.h>

namespace utils
{
	class LogsManager : public utils::Singleton<LogsManager>
	{
	public:
		using logger_s_ptr_t = std::shared_ptr<spdlog::logger>;
		using loggers_map_t = std::map<std::string, logger_s_ptr_t>;

		void Init();
		bool Update();

	private:
		static std::vector<std::string> m_names;
		loggers_map_t m_loggers;
	};
} // namespace utils
