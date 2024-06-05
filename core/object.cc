#include "object.h"

u64 object::spawn(object *obj) {
  this->u->all.push_back(obj);
  return this->u->all.size()-1;
}

void object::awake(u64 id) {
  this->u->active.insert(this->u->all[id]);
}

void object::asleep(u64 id) {
  this->u->active.erase(this->u->all[id]);
}
