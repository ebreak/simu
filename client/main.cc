#include <GLFW/glfw3.h>
#include <cstdio>

#include <universe.h>
#include <object/human.h>
#include <mocutils/clock.h>

void render(universe &u) {
  moc::clock start;
  while (true) {
    auto ro_data = u.ro_obj();
    for (auto obj: ro_data)
      printf("rendering %d\n", obj->kind);
    start.tick(1000);
  }
}

int main() {
  universe u;
  auto id = u.insert(new human(&u, coordinate(0, 0)));
  u.activate(id);
  u.start(100, false);
  return 0;
}
