#include "human.h"

void human::tick_action() {
  this->u->insert(new human(this->u, this->position));
}
