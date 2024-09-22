#pragma once

#include <config/FileConfigReaderBase.h>

namespace config
{
	class GeneralJsonConfigReader : public FileConfigReaderBase
	{
	public:
		GeneralJsonConfigReader(const std::string & sFilePath);
		bool Read(ConfigDataBase & baseData) override;
	};
} // namespace config