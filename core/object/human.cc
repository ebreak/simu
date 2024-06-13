#include "human.h"

#include "kind.h"

human::human(universe *u, coordinate _position): object(u, obj_human, _position) {
}

void human::tick_action() {
}

void human::move(coordinate delta) {
  this->lock.lock();
  this->position += delta;
  this->lock.unlock();
}

moc::bytes human::serialize() {
  this->lock.lock();
  moc::bytes ret(this, sizeof(human));
  this->lock.unlock();
  return ret;
}
