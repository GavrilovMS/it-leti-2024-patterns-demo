#include <config/ConfigDI/ConfigDI.h>
#include <utils/InitLogs.h>

#include <spdlog/spdlog.h>

int main(int, char **)
{
	spdlog::info("Starting CallCenter...");
	config::ConfigDI::Instance().Init();
	utils::InitLogs();
	return 0;
}
