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

void universe::start(u64 n) {
  moc::clock c;
  i64 used = 0;
  while (n--) {
    printf("\rtick: %d, CPU: %llf%%, obj: %d", tick, (double) used / 10, all.size());

    all_lock.lock();
    active_lock.lock();
    for (auto v: active)
      v->tick_action();
    active_lock.unlock();
    all_lock.unlock();

    tick += 1;
    c.tick(1000);
  }
}

const object *universe::operator[](u64 id) {
  all_lock.lock();
  const object *ret = all[id];
  all_lock.unlock();
  return ret;
}

void universe::insert(object *obj) {
  all_lock.lock();
  all.push_back(obj);
  all_lock.unlock();
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
