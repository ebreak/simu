#include "human.h"

#include "kind.h"

void human::tick_action() {
  this->position += this->velocity;
}

moc::bytes human::serialize() {
  moc::bytes ret(this, sizeof(human));
  return ret;
}
