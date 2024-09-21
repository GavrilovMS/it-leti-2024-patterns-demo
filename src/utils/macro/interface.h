#pragma once

#include <utils/macro/ptrable.h>

#ifndef INTERFACE
#define INTERFACE(className)\
virtual ~className() = default;\
FULLY_PTRABLE(className)
#endif // INTERFACE