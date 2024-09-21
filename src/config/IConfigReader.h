#pragma once

#include <utils/macro/interface.h>
#include <config/ConfigLoadTraits.h>

namespace config
{
	class IConfigReader
	{
	public:
		INTERFACE(IConfigReader)
		virtual bool Read(ConfigLoadTraits::s_ptr_t pTraits) = 0;
	};
}; // namespace config
