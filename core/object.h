#ifndef __CORE_OBJECT_H
#define __CORE_OBJECT_H

#include "coordinate.h"

class universe;
#include "universe.h"

struct object {
  i64 kind; // > 0 for renderable, <= 0 for unrenderable
  universe *u;
  coordinate position;
  object(universe *_u, i64 _kind, coordinate _position)
    :u(_u), kind(_kind), position(_position) {}
  virtual void tick_action() = 0;
  u64 spawn(object *obj);
  void awake(u64 id);
  void asleep(u64 id);
};

#endif