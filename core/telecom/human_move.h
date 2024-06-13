#ifndef _CORE_TELECOM_HUMAN_MOVE_H
#define _CORE_TELECOM_HUMAN_MOVE_H

#include <mocutils/type.h>

#include "basic.h"
#include "coordinate.h"

struct human_move: basic {
  u64 id;
  coordinate delta;
};

#endif