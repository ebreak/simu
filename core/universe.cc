#include "universe.h"

#include <mocutils/log.h>
#include <mocutils/clock.h>
#include <object/kind.h>
#include <object/human.h>

#include "config.h"

universe::universe(moc::bytes &raw): tick(0) {
  int obj_num = raw.next_int32();
  this->all.reserve(obj_num);
  while (obj_num--) {
    int kind = raw.next_int32();
    int obj_len = raw.next_int32();
    object *obj = nullptr;

    // append here to add obj impl
    if (kind == obj_human)
      obj = human::deserialize(this, raw.range(raw.ptr, raw.ptr+obj_len));

    raw.ptr += obj_len;
    this->all.push_back(obj);
  }
  
  int active_num = raw.next_int32();
  while (active_num--)
    this->active.insert(this->all[raw.next_int32()]);
}

universe::~universe() {
  for (auto v: all)
    delete v;
}

void universe::start() {
  moc::clock c;
  i64 used = 0;
  while (true) {
    all_lock.lock();
    active_lock.lock();
    for (auto v: active)
      v->tick_action();
    active_lock.unlock();
    all_lock.unlock();

    tick += 1;
    used = c.tick(PLANCK_TIME);
  }
}

const object *universe::operator[](u64 id) {
  all_lock.lock();
  const object *ret = all[id];
  all_lock.unlock();
  return ret;
}

std::vector<const object*> universe::ro_obj() {
  std::vector<const object *> ret;
  ret.reserve(this->all.size());
  for (int i = 0; i < this->all.size(); ++i)
    ret.push_back(this->all[i]);
  ret.resize(this->all.size());
  return ret;
}

u64 universe::insert(object *obj) {
  all_lock.lock();
  all.push_back(obj);
  u64 id = all.size()-1;
  all_lock.unlock();
  obj->id = id;
  return id;
}

void universe::update(u64 id, object *obj, bool _active) {
  all_lock.lock();
  if (all.size() <= id) {
    auto old_size = all.size();
    all.resize(id+1);
    for (auto i = old_size; i <= id; ++i)
      all[i] = nullptr;
  }
  if (all[id] != nullptr) delete all[id];
  obj->id = id;
  all[id] = obj;
  all_lock.unlock();
  if (!_active) return;
  active_lock.lock();
  active.insert(obj);
  active_lock.unlock();
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

moc::bytes universe::serialize() {
  moc::bytes ret;
  all_lock.lock();
  active_lock.lock();
  // serialize 'all'
  ret += (i32) all.size();
  for (auto obj: all) {
    ret += (i32) obj->kind;
    auto serial = obj->serialize();
    ret += (i32) serial.size();
    ret += serial;
  }
  // serialize 'active'
  ret += (i32) active.size();
  for (auto obj: active)
    ret += (i32) obj->id;
  active_lock.unlock();
  all_lock.unlock();
  return ret;
}
