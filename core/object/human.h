#ifndef __CORE_OBJECT_HUMAN_H
#define __CORE_OBJECT_HUMAN_H

#include "object.h"

struct human: public object {
  u64 last_spawn;
  human(universe *u, coordinate _position);
  void tick_action();
};


#endif