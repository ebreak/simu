#include <GLFW/glfw3.h>
#include <cstdio>
#include <thread>
#include <universe.h>
#include <object/human.h>
#include <mocutils/clock.h>

#include "ui.h"

int main() {
  universe u;
  auto id = u.insert(new human(&u, coordinate(0, 0)));
  u.activate(id);
  std::thread render_thread(render, &u);
  u.start(100, false);
  return 0;
}
