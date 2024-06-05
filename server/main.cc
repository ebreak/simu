#include <universe.h>
#include <object/human.h>

#include <mocutils/log.h>

int main() {
  universe u;
  u.insert(new human(&u, coordinate(0, 0)));
  u.start(-1);
  return 0;
}
