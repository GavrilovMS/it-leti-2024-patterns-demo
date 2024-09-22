#pragma once

#include <config/IFileConfigReader.h>

namespace config
{
	class ConfigDataBase
	{
	public:
		FULLY_PTRABLE(ConfigDataBase)
		virtual ~ConfigDataBase() = default;

		bool Load(IFileConfigReader::s_ptr_t pReader) { return pReader ? pReader->Read(*this) : false; }
	};
} // namespace config