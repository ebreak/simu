#ifndef __CORE_UNIVERSE_H
#define __CORE_UNIVERSE_H

#include <mocutils/type.h>
#include <set>
#include <vector>
#include <mutex>

#include "object.h"

class universe {
  std::vector<object*> all;
  std::set<const object*> active;
  std::mutex all_lock, active_lock;
public:
  i64 tick;
  universe();
  ~universe();
  void start(u64 n);
  const object *operator[](u64 id);
  void activate(u64 id);
  void deactivate(u64 id);
};

#endif