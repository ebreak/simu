#include "human.h"

#include "kind.h"

void human::tick_action() {
  this->position += this->velocity;
}
