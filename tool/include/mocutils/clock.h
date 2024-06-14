#ifndef __MOC_CLOCK_H
#define __MOC_CLOCK_H

#include "type.h"

namespace moc {

i64 get_tick();

struct clock {
  i64 last;
  clock();
  // returns ms since last leave clock.tick
  i64 tick(i64 period_time);
};

};

#endif