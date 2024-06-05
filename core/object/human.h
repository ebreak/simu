#ifndef __CORE_OBJECT_HUMAN_H
#define __CORE_OBJECT_HUMAN_H

#include "object.h"

struct human: public object{
  human(universe *u): object(u) {};
  void tick_action();
};


#endif