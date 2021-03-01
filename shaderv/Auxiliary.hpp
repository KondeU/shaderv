#ifndef _AUXILIARY_HPP_
#define _AUXILIARY_HPP_

constexpr char* APP_NAME = "shaderv";
constexpr char* APP_VERS = "0.2021.4.0";

#ifdef _DEBUG
constexpr char* APP_DATE = __DATE__;
constexpr char* APP_TIME = __TIME__;
#else
constexpr char* APP_DATE = "Dec 25 2021";
constexpr char* APP_TIME = "Christmas Eve";
#endif

#include "../auxiliary/dfx/DFX.h"

#endif
