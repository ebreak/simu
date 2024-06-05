#include "human.h"

void human::tick_action() {
  this->u += new human(u);
}
