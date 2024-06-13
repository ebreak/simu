#ifndef __CORE_UNIVERSE_H
#define __CORE_UNIVERSE_H

#include <mocutils/type.h>
#include <set>
#include <vector>
#include <mutex>
#include <mocutils/byte.h>

struct object;
#include "object.h"

class universe {
  friend struct object;
  std::vector<object*> all;
  std::set<object*> active;
  std::mutex all_lock, active_lock;
public:
  u64 tick;
  universe();
  universe(moc::bytes &raw);
  ~universe();
  void start(i64 period, bool show_status);
  const object *operator[](u64 id);
  std::vector<const object*> ro_obj();
  u64 insert(object *obj);
  void activate(u64 id);
  void deactivate(u64 id);
  moc::bytes serialize();
};

#endif