#include "game.h"

#include "net.h"

universe *u;

void start() {
  u = new universe(c->promise("get-universe", PRT_NULL_PKG));
  moc::logf("universe inited with %d objs\n", u->ro_obj().size());
}
