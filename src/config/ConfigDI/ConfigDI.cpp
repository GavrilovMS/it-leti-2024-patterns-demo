#include <config/ConfigDI/ConfigDI.h>

namespace config
{
	void ConfigDI::Init(const std::string & sFilePath, IFileConfigReader::s_ptr_t pReader)
	{
		m_sFilePath = sFilePath;
		if (pReader)
		{
			m_pReader = pReader;
			m_pReader->SetFilePath(m_sFilePath);
		}
		Update();
	}

	void ConfigDI::Init(IFileConfigReader::s_ptr_t pReader)
	{
		if (pReader)
		{
			m_pReader = pReader;
			m_pReader->SetFilePath(m_sFilePath);
		}
		Update();
	}

	bool ConfigDI::Update()
	{
		auto pNewData = std::make_unique<ConfigData>();
		if (pNewData->Load(m_pReader))
		{
			std::unique_lock<std::mutex>(m_mtx);
			m_pData = std::move(pNewData);
			return true;
		}
		return false;
	}
} // namespace config
