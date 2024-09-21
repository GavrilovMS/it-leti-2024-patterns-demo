#pragma once

#include <utils/macro/ptrable.h>

namespace config
{
	class ConfigLoadTraits
	{
	public:
		FULLY_PTRABLE(ConfigLoadTraits)
		virtual ~ConfigLoadTraits() = default;
	};
} // namespace config
