#include "human.h"

void human::tick_action() {
  u64 id = this->spawn(new human(this->u, coordinate(0, 0)));
}
