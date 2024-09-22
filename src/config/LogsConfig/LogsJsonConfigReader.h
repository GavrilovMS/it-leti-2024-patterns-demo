#pragma once

#include <config/FileConfigReaderBase.h>

namespace config
{
	class LogsJsonConfigReader : public FileConfigReaderBase
	{
	public:
		LogsJsonConfigReader(const std::string & sFilePath);
		bool Read(ConfigDataBase & baseData) override;
	};
} // namespace config