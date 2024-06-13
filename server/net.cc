#include "net.h"

#include <pyrite/server.h>

#include "user.h"

prt::server *s;

void init_server() {
  s = new prt::server(8082);
  s->set_handler("login", _login);
  moc::log("server init ok");
}
