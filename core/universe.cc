#include "universe.h"

#include <mocutils/log.h>
#include <mocutils/clock.h>

universe::universe() {
  moc::log("initializing the universe");
  tick = 0;
}

void universe::start(u64 n) {
  moc::clock c;
  i64 used = 0;
  while (n--) {
    printf("\rtick: %d, server load: %llf%%", tick, (double) used / 10);

    tick += 1;
    c.tick(1000);
  }
}
