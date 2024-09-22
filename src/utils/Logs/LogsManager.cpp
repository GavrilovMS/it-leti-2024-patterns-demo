#include <config/LogsConfig/LogsConfigDI.h>
#include <utils/Logs/LogsManager.h>

namespace utils
{
	void LogsManager::Init()
	{
		const auto & logs = config::LogsConfigDI::Instance().Logs();
		for (const auto & log : logs)
		{ }
	}

	bool LogsManager::Update()
	{
		return true;
	}
} // namespace utils
