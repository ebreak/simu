#ifndef __CORE_OBJECT_ASTRO_H
#define __CORE_OBJECT_ASTRO_H

#include "object.h"
#include "kind.h"
#include <vector.h>
#include <mocutils/byte.h>

struct astro: public object {
  bool fixed;
  double massive;
  vector velocity;
  astro(universe *u)
    :object(u, obj_astro, coordinate()), fixed(false), velocity(vector()) {}
  astro(universe *u, coordinate _position)
    :object(u, obj_astro, _position), fixed(false), velocity(vector()) {}
  void tick_action();

  moc::bytes serialize() {
    moc::bytes ret(this, sizeof(astro));
    return ret;
  }

  static object* deserialize(universe *u, moc::bytes data) {
    astro tmp(u), *ret = new astro(u);
    data.to_mem(&tmp, sizeof(tmp));
    // to make vtable work, use '=', not memcpy
    // if memcpy is used, the vtable is from remote, 
    // which will not work here
    *ret = tmp;
    ret->u = u;
    return ret;
  }
};

#endif