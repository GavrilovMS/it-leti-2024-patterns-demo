#pragma once

#include <config/IFileConfigReader.h>

namespace config
{
	class FileConfigReaderBase : public IFileConfigReader
	{
	public:
		FileConfigReaderBase(const std::string & sFilePath)
		: m_sFilePath { sFilePath }
		{ }

		void SetFilePath(const std::string & sFilePath) override { m_sFilePath = sFilePath; }

	protected:
		std::string m_sFilePath;
	};
} // namespace config
