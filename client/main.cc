#include <GLFW/glfw3.h>
#include <cstdio>
#include <thread>
#include <universe.h>
#include <object/human.h>
#include <mocutils/clock.h>
#include <mocutils/channel.h>

#include "ui.h"
#include "net.h"
#include "game.h"

int main() {
  init_client();
  std::thread t(start);
  ui_mainloop();
  return 0;
}
