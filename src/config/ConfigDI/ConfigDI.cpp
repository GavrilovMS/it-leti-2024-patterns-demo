#include <config/ConfigDI/ConfigDI.h>

#include <spdlog/spdlog.h>

namespace config
{
	void ConfigDI::Init(const std::string & sFilePath, IFileConfigReader::s_ptr_t pReader)
	{
		m_sFilePath = sFilePath;
		Init(pReader);
	}

	void ConfigDI::Init(IFileConfigReader::s_ptr_t pReader)
	{
		if (pReader)
		{
			m_pReader = pReader;
			m_pReader->SetFilePath(m_sFilePath);
		}
		if (!Update())
			spdlog::warn("Failed to init config. Use default values.");
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

	const std::string & ConfigDI::Ip() const
	{
		return m_pData->m_sIpAddress;
	}

	const uint32_t & ConfigDI::Port() const
	{
		return m_pData->m_nPort;
	}

	const std::string & ConfigDI::LogsLevel() const
	{
		return m_pData->m_sLogsLevel;
	}

	const std::string & ConfigDI::LogsPath() const
	{
		return m_pData->m_sLogsFilePath;
	}

	const std::string & ConfigDI::LogsPattern() const
	{
		m_pData->m_sLogsPattern;
	}

} // namespace config
