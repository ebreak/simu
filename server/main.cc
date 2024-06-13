#include <universe.h>

#include <mocutils/log.h>
#include <object/human.h>

#include "net.h"
#include "user.h"

int main() {
  init_user();
  init_server();
  universe u;
  auto id = u.insert(new human(&u, coordinate(0, 0)));
  u.activate(id);
  u.start(100, false);
  return 0;
}
