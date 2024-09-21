#pragma once

#include <memory>

#include <config/IFileConfigReader.h>

namespace config
{
	class ConfigData
	: public ConfigLoadTraits
	, public std::enable_shared_from_this<ConfigData>
	{
	public:
		FULLY_PTRABLE(ConfigData)
		bool Load(IFileConfigReader::s_ptr_t pReader);
	};
} // namespace config
