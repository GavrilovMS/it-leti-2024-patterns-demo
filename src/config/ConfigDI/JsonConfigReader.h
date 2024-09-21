#pragma once

#include <config/IFileConfigReader.h>

namespace config
{
	class JsonConfigReader : public IFileConfigReader
	{
	public:
		JsonConfigReader(const std::string & sFilePath);
		bool Read(ConfigLoadTraits::s_ptr_t pTraits) override;
		void SetFilePath(const std::string & sFilePath) override;

	private:
		std::string m_sFilePath;
	};
} // namespace config