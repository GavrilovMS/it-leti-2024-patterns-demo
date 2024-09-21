#include <config/ConfigDI/ConfigDI.h>
#include <utils/InitLogs.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks-inl.h>

void utils::InitLogs()
{
	spdlog::default_logger()->sinks().clear();
	if (config::ConfigDI::Instance().LogsEnabled())
	{
		auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(config::ConfigDI::Instance().LogsPath());
		file_sink->set_level(spdlog::level::from_str(config::ConfigDI::Instance().LogsLevel()));
		file_sink->set_pattern(config::ConfigDI::Instance().LogsPattern());
		spdlog::default_logger()->sinks().push_back(file_sink);
	}
}