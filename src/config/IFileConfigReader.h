#pragma once

#include <string>

#include <utils/macro/interface.h>

namespace config
{
	class ConfigDataBase;

	class IFileConfigReader
	{
	public:
		INTERFACE(IFileConfigReader)
		virtual bool Read(ConfigDataBase & baseData) = 0;
		virtual void SetFilePath(const std::string & sFilePath) = 0;
	};
}; // namespace config
