#ifndef __CORE_OBJECT_HUMAN_H
#define __CORE_OBJECT_HUMAN_H

#include "object.h"
#include "kind.h"
#include <vector.h>
#include <mocutils/byte.h>

struct human: public object {
  EXTEND_TRAITS(human);
  vector velocity;
  human(universe *u, coordinate _position)
    :object(u, obj_human, _position), velocity(vector()) {}
  void tick_action();
};


#endif