#include "human.h"

#include "kind.h"

human::human(universe *u, coordinate _position): object(u, obj_human, _position) {
  last_spawn = this->u->tick;
}

void human::tick_action() {
}

void human::move(coordinate delta) {
  this->position += delta;
}
