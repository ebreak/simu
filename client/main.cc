#include <GLFW/glfw3.h>
#include <cstdio>
#include <thread>
#include <universe.h>
#include <object/human.h>
#include <mocutils/clock.h>

#include "ui.h"
#include "net.h"

int main() {
  init_client();
  return 0;
  universe u;
  auto me = new human(&u, coordinate(0, 0));
  auto id = u.insert(me);
  u.activate(id);
  std::thread ui_thread(ui_mainloop, &u, me);
  u.start(100, false);
  return 0;
}
