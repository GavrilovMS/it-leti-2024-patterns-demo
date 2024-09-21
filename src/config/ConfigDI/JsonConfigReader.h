#include <config/IConfigReader.h>

namespace config
{
	class JsonConfigReader : public IConfigReader
	{
	public:
		bool Read(ConfigLoadTraits::s_ptr_t pTraits) override;
	};
} // namespace config