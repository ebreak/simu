#include <universe.h>

#include <mocutils/log.h>
#include <object/human.h>

#include "net.h"
#include "user.h"
#include "game.h"

int main() {
  init_user();
  init_server();
  start();
  return 0;
}
