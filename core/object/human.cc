#include "human.h"

#include "kind.h"

human::human(universe *u, coordinate _position): object(u, obj_human, _position) {
  last_spawn = this->u->tick;
}

void human::tick_action() {
  if (this->u->tick - last_spawn < 100)
    return;
  last_spawn = this->u->tick;
  u64 id = this->spawn(new human(
    this->u, 
    coordinate(this->position.x + 1, this->position.y + 1)
  ));
  this->awake(id);
}
