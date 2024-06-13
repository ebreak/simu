#include "net.h"

#include <pyrite/client.h>
#include <object/human.h>

#include "game.h"

prt::client *c;
u64 session;

prt::bytes _human_move(prt::bytes data);

void init_client() {
  c = new prt::client("127.0.0.1", 8082);
  c->set_handler("human-move", _human_move);
  c->async();

  prt::bytes login_data;
  login_data += std::string("nahida");
  login_data += std::string("akademiya");
  auto resp = c->promise("login", login_data);
  resp.to_mem(&session, sizeof(session));
  if (session == -1)
    moc::panic("invalid username or password");
  moc::logf("login success. session: %llx\n", session);
}

prt::bytes _human_move(prt::bytes data) {
  u64 oid;
  data.range(0, 8).to_mem(&oid, sizeof(oid));
  coordinate delta;
  data.range(8, data.size()).to_mem(&delta, sizeof(delta));

  auto ho = const_cast<object*>(u->operator[](oid));
  human *h = static_cast<human*>(ho);
  h->move(delta);
  return PRT_NORESP;
}
