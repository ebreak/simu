#ifndef __CORE_UNIVERSE_H
#define __CORE_UNIVERSE_H

#include <mocutils/type.h>
#include <list>

#include "object.h"

struct universe {
  i64 tick;
  std::list<object*> active, deactive;
  universe();
  void start(u64 n);
};

#endif