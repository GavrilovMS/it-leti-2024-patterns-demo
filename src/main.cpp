#include <config/GeneralConfig/GeneralConfigDI.h>
#include <config/LogsConfig/LogsConfigDI.h>

#include <spdlog/spdlog.h>

int main(int, char **)
{
	spdlog::info("Starting CallCenter...");
	config::GeneralConfigDI::Instance().Init();
	config::LogsConfigDI::Instance().Init();

	return 0;
}
