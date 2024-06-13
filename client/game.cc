#include "game.h"

#include <mocutils/channel.h>

#include "net.h"

universe *u;

void start() {
  auto resp = c->promise("get-universe", PRT_NULL_PKG);
  u = new universe(resp);
  u->start(100, false);
}
