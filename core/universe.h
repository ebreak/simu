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
  universe(): tick(0) {}
  universe(moc::bytes &raw);
  ~universe();
  void start();
  const object *operator[](u64 id);
  std::vector<const object*> ro_obj();
  u64 insert(object *obj);
  void update(u64 id, object *obj, bool _active);
  void activate(u64 id);
  void deactivate(u64 id);
  moc::bytes serialize();
};

#endif