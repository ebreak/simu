#include "object.h"

object *object::visit(u64 id) {
  return this->u->all[id];
}

std::vector<u64> object::find(i64 kind) {
  std::vector<u64> ret;
  for (auto v: this->u->category[kind])
    ret.push_back(v);
  return ret;
}

u64 object::spawn(object *obj) {
  this->u->all.push_back(obj);
  u64 id = this->u->all.size()-1;
  obj->id = id;
  return id;
}

void object::awake(u64 id) {
  this->u->active.insert(this->u->all[id]);
}

void object::asleep(u64 id) {
  this->u->active.erase(this->u->all[id]);
}
