#ifndef __CORE_OBJECT_H
#define __CORE_OBJECT_H

#include <mutex>
#include <mocutils/byte.h>

#include "coordinate.h"

class universe;
#include "universe.h"

struct object {
  u64 id;
  i64 kind; // > 0 for renderable, <= 0 for unrenderable
  universe *u;
  coordinate position;
  std::mutex lock;
  object(universe *_u, i64 _kind, coordinate _position)
    :u(_u), kind(_kind), position(_position) {}
  virtual void tick_action() = 0;
  u64 spawn(object *obj);
  void awake(u64 id);
  void asleep(u64 id);
  virtual moc::bytes serialize() = 0;

  static object *unserialize(moc::bytes &data) {
    object *ret = (object *) new void[data.size()];
    data.to_mem(ret, data.size());
    return ret;
  }
};

#endif