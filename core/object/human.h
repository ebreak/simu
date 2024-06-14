#ifndef __CORE_OBJECT_HUMAN_H
#define __CORE_OBJECT_HUMAN_H

#include "object.h"
#include "kind.h"
#include <vector.h>

struct human: public object {
  vector velocity;
  human(universe *u, coordinate _position)
    :object(u, obj_human, _position), velocity(vector()) {}
  void tick_action();
  void move(coordinate delta);
  moc::bytes serialize();
};


#endif