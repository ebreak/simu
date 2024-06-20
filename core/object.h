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
  object(universe *_u, i64 _kind, coordinate _position)
    :u(_u), kind(_kind), position(_position) {}
  virtual void tick_action() = 0;
  object *visit(u64 id);
  std::vector<u64> find(i64 kind);
  u64 spawn(object *obj);
  void awake(u64 id);
  void asleep(u64 id);
  virtual moc::bytes serialize() = 0;
};

#define EXTEND_TRAITS(obj_impl) \
obj_impl(universe *u): object(u, obj_##obj_impl, coordinate()), velocity(vector()) {} \
moc::bytes serialize() { \
  moc::bytes ret(this, sizeof(obj_impl)); \
  return ret; \
} \
\
static object* deserialize(universe *u, moc::bytes data) { \
  obj_impl tmp(u), *ret = new obj_impl(u); \
  data.to_mem(&tmp, sizeof(tmp)); \
  *ret = tmp; \
  ret->u = u; \
  return ret; \
}

#endif