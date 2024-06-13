#include "human.h"

#include "kind.h"

human::human(universe *u, coordinate _position): object(u, obj_human, _position) {
}

void human::tick_action() {
}

void human::move(coordinate delta) {
  this->position += delta;
}

moc::bytes human::serialize() {
  moc::bytes ret(this, sizeof(human));
  return ret;
}
