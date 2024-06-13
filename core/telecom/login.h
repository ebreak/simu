#ifndef _CORE_TELECOM_LOGIN_H
#define _CORE_TELECOM_LOGIN_H

#include <string>

#include "basic.h"

struct login: basic {
  std::string username, password;
};

#endif