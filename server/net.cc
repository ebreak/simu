#include "net.h"

#include <pyrite/server.h>
#include <thread>

#include "user.h"
#include "game.h"

prt::server *s;

void init_server() {
  s = new prt::server(8082);
  s->set_handler("login", _login);
  s->set_handler("get-universe", _get_universe);
  s->set_handler("human-move", _human_move);
  s->async();
  moc::log("server init ok");
}

void update_object(object *obj, bool active) {
  prt::bytes data(&active, sizeof(active));
  data += (i32) obj->kind;
  data += obj->serialize();
  tell_all("update-object", data);
}
