#pragma once

#include <memory>

#ifndef UHIQUE_PTRABLE
#define UHIQUE_PTRABLE(className)\
using u_ptr_t = std::unique_ptr<className>;
#endif // UHIQUE_PTRABLE

#ifndef SHARED_PTRABLE
#define SHARED_PTRABLE(className)\
using s_ptr_t = std::shared_ptr<className>;
#endif // SHARED_PTRABLE

#ifndef FULLY_PTRABLE
#define FULLY_PTRABLE(className)\
UHIQUE_PTRABLE(className)\
SHARED_PTRABLE(className)
#endif //FULLY_PTRABLE