#ifndef __CORE_OBJECT_HUMAN_H
#define __CORE_OBJECT_HUMAN_H

#include "object.h"

struct human: public object {
  human(universe *u, coordinate _position);
  void tick_action();
  void move(coordinate delta);
};


#endif