#ifndef __CORE_OBJECT_H
#define __CORE_OBJECT_H

#include "coordinate.h"

class universe;

struct object {
  universe *u;
  coordinate position;
  object(universe *_u, coordinate _position): u(_u), position(_position) {}
  virtual void tick_action() = 0;
};

#endif