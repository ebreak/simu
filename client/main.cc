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

int main(int argc, char **argv) {
  if (argc < 3)
    moc::panicf("invalid argc: %d\n", argc);
  int port = atoi(argv[2]);
  char username[20], password[20];
  printf("username> ");
  scanf("%s", username);
  printf("password> ");
  scanf("%s", password);
  init_client(std::string(username), std::string(password), argv[1], port);
  std::thread t(start);
  ui_main();
  return 0;
}
