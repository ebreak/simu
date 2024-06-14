#include "astro.h"

#include <config.h>
#include <cmath>

void astro::tick_action() {
  if (this->fixed) return;

  // F = GRAVITY*m1*m2/r/r
  vector force;
  auto all = this->find(obj_astro);
  for (auto id: all) {
    if (id == this->id) continue;
    auto other = (astro *) this->visit(id);
    double d = this->position.distance_to(other->position);
    double r = d * 32;
    double g = GRAVITY*(this->massive)*(other->massive)/r/r;
    double dx = other->position.x - this->position.x;
    double dy = other->position.y - this->position.y;
    force.x += g * dx / d;
    force.y += g * dy / d;
  }

  // f = ma, a = f/m
  vector accelerate = force / this->massive;
  this->velocity += accelerate;
  this->position += this->velocity;
}
