#ifndef __CORE_OBJECT_ASTRO_H
#define __CORE_OBJECT_ASTRO_H

#include "object.h"
#include "kind.h"
#include <vector.h>
#include <mocutils/byte.h>

struct astro: public object {
  EXTEND_TRAITS(astro);
  bool fixed;
  double massive;
  vector velocity;
  astro(universe *u, coordinate _position)
    :object(u, obj_astro, _position), fixed(false), velocity(vector()) {}
  void tick_action();
};
REGIST_OBJ(astro);

#endif