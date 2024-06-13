#include "game.h"

#include <universe.h>

universe *u;

void start() {
  u = new universe;
  u->start(100, false);
}

prt::bytes _get_universe(sockaddr_in client, prt::bytes data) {
  return u->serialize();
}
