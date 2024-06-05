#include "human.h"

void human::tick_action() {
  auto new_man = new human(this->u, coordinate(0, 0));
  this->u->all.push_back(new_man);
  this->u->active.insert(new_man);
}
