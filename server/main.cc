#include <universe.h>
#include <object/human.h>

#include <mocutils/log.h>

int main() {
  universe u;
  auto id = u.insert(new human(&u, coordinate(0, 0)));
  u.activate(id);
  u.start(100);
  return 0;
}
