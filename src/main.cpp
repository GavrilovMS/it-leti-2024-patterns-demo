#include <config/GeneralConfig/GeneralConfigDI.h>

#include <utils/Logs/LogsManager.h>
#include <spdlog/spdlog.h>

int main(int, char **)
{
	spdlog::info("Starting CallCenter...");
	utils::LogsManager::Instance().Init();
	config::GeneralConfigDI::Instance().Init();

	return 0;
}
