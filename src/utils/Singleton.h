#pragma once

namespace utils
{
	template<typename T>
	class Singleton
	{
	public:
		static T & Instance()
		{
			static T instance;
			return instance;
		}

	protected:
		Singleton() = default;
		~Singleton() = default;
	};
} // namespace utils
