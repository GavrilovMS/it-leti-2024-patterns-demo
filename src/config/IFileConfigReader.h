#pragma once

#include <string>

#include <utils/macro/interface.h>
#include <config/ConfigLoadTraits.h>

namespace config
{
	class IFileConfigReader
	{
	public:
		INTERFACE(IFileConfigReader)
		virtual bool Read(ConfigLoadTraits::s_ptr_t pTraits) = 0;
		virtual void SetFilePath(const std::string & sFilePath) = 0;
	};
}; // namespace config
