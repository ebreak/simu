#ifndef __CORE_OBJECT_HUMAN_H
#define __CORE_OBJECT_HUMAN_H

#include "object.h"
#include "kind.h"
#include <vector.h>
#include <mocutils/byte.h>

struct human: public object {
  vector velocity;
  human(universe *u): object(u, obj_human, coordinate()), velocity(vector()) {}
  human(universe *u, coordinate _position)
    :object(u, obj_human, _position), velocity(vector()) {}
  void tick_action();

  moc::bytes serialize() {
    moc::bytes ret(this, sizeof(human));
    return ret;
  }

  static object* deserialize(universe *u, moc::bytes data) {
    human tmp(u), *ret = new human(u);
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