#include "astro.h"

#include <config.h>

void astro::tick_action() {
  if (this->fixed) return;

  // F = GRAVITY*m1*m2/r/r
  polar pforce;
  auto all = this->find(obj_astro);
  for (auto id: all) {
    if (id == this->id) continue;
    auto other = (astro *) this->visit(id);
    double r = this->position.distance_to(other->position);
    auto p = this->position.polar_to(other->position);
    p.d = GRAVITY*this->massive*other->massive/r/r;
    pforce += p;
  }

  // f = ma, a = f/m
  vector force(pforce);
  vector accelerate = force / this->massive;
  this->velocity += accelerate;
  this->position += this->velocity;
}
