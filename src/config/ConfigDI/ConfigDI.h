#pragma once

#include <mutex>

#include <config/ConfigDI/ConfigData.h>
#include <config/ConfigDI/JsonConfigReader.h>
#include <config/IConfigReader.h>

#include <utils/Singleton.h>

namespace config
{
#ifndef DEFAULT_CONFIG_READER
	typedef JsonConfigReader DEFAULT_CONFIG_READER;
#endif

	class ConfigDI : public utils::Singleton<ConfigDI>
	{
	public:
		void Init(IConfigReader::s_ptr_t pReader = nullptr);

		bool Update();

	private:
		std::mutex m_mtx;
		ConfigData::u_ptr_t m_pData { std::make_unique<ConfigData>() };
		IConfigReader::s_ptr_t m_pReader { std::make_shared<DEFAULT_CONFIG_READER>() };
	};
} // namespace config
