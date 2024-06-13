#include "game.h"

#include <universe.h>

universe *u;

void start() {
  u = new universe;
  u.start(100, false);
}
