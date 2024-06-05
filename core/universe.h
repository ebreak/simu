#ifndef __CORE_UNIVERSE_H
#define __CORE_UNIVERSE_H

#include <mocutils/type.h>
#include <set>
#include <vector>
#include <mutex>

#include "object.h"

class universe {
  std::set<object*> active;
  std::mutex all_lock, active_lock;
public:
  i64 tick;
  std::vector<object*> all;
  universe();
  ~universe();
  void start(u64 n);
  void activate(u64 id);
  void deactivate(u64 id);
};

#endif