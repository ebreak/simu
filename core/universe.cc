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

void universe::activate(u64 id) {
  active_lock.lock();
  active.insert(this->operator[](id));
  active_lock.unlock();
}

void universe::deactivate(u64 id) {
  active_lock.lock();
  active.erase(this->operator[](id));
  active_lock.unlock();
}
