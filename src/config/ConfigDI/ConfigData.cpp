#include <config/ConfigDI/ConfigData.h>

namespace config
{
	bool ConfigData::Load(IConfigReader::s_ptr_t pReader)
	{
		return pReader->Read(shared_from_this());
	}
} // namespace config
