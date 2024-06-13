#ifndef _CORE_TELECOM_USER_H
#define _CORE_TELECOM_USER_H

#include <mocutils/type.h>
#include <string>
#include <object/human.h>

struct user {
  u64 id;
  std::string username, password;
};

#endif