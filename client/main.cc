#include <GLFW/glfw3.h>
#include <cstdio>
#include <thread>
#include <universe.h>
#include <object/human.h>
#include <mocutils/clock.h>

#include "ui.h"
#include "net.h"
#include "game.h"

int main() {
  init_client();
  std::thread ui_thread(ui_mainloop);
  start();
  return 0;
}
