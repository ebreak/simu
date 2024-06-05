#ifndef __CORE_UNIVERSE_H
#define __CORE_UNIVERSE_H

#include <mocutils/type.h>

struct universe {
  i64 tick;
  universe();
  void start(u64 n);
};

#endif