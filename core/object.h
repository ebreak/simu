#ifndef __CORE_OBJECT_H
#define __CORE_OBJECT_H

#include "coordinate.h"

class universe;
#include "universe.h"

struct object {
  universe *u;
  coordinate position;
  object(universe *_u, coordinate _position): u(_u), position(_position) {}
  virtual void tick_action() = 0;
  u64 spawn(object *obj);
  void awake(u64 id);
  void asleep(u64 id);
};

#endif