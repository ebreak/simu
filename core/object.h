#ifndef __CORE_OBJECT_H
#define __CORE_OBJECT_H

#include "coordinate.h"

struct object {
  coordinate position;
  virtual void tick_action() = 0;
};

#endif