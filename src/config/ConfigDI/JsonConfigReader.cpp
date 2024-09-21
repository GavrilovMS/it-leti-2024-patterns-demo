#include <config/ConfigDI/JsonConfigReader.h>

namespace config
{
	JsonConfigReader::JsonConfigReader(const std::string & sFilePath)
	: m_sFilePath { sFilePath }
	{ }

	bool JsonConfigReader::Read(ConfigLoadTraits::s_ptr_t pTraits)
	{
		return true;
	}

	void JsonConfigReader::SetFilePath(const std::string & sFilePath)
	{
		m_sFilePath = sFilePath;
	}
} // namespace config
