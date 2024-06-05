#include "universe.h"

#include <mocutils/log.h>
#include <mocutils/clock.h>

universe::universe() {
  moc::log("initializing the universe");
  tick = 0;
}

universe::~universe() {
  for (auto v: all)
    delete v;
}

void universe::start(i64 period) {
  moc::clock c;
  i64 used = 0;
  while (true) {
    if (tick % 10 == 0)
      printf("\rCPU: %.2llf%%, obj: %d", (double) used / period, all.size());

    all_lock.lock();
    active_lock.lock();
    for (auto v: active)
      v->tick_action();
    active_lock.unlock();
    all_lock.unlock();

    tick += 1;
    used = c.tick(period);
  }
}

const object *universe::operator[](u64 id) {
  all_lock.lock();
  const object *ret = all[id];
  all_lock.unlock();
  return ret;
}

u64 universe::insert(object *obj) {
  all_lock.lock();
  all.push_back(obj);
  u64 id = all.size()-1;
  all_lock.unlock();
  return id;
}

void universe::activate(u64 id) {
  active_lock.lock();
  all_lock.lock();
  active.insert(all[id]);
  all_lock.unlock();
  active_lock.unlock();
}

void universe::deactivate(u64 id) {
  active_lock.lock();
  all_lock.lock();
  active.erase(all[id]);
  all_lock.unlock();
  active_lock.unlock();
}
