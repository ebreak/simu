#ifndef __CORE_OBJECT_H
#define __CORE_OBJECT_H

#include "coordinate.h"

struct object {
  universe *u;
  coordinate position;
  object(universe *u): u(u) {}
  virtual void tick_action() = 0;
};

#endif