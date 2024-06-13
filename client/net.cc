#include "net.h"

#include <pyrite/client.h>
#include <telecom/human_move.h>
#include <object/human.h>

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
  moc::logf("login success. session: %llx", session);
}

std::vector<human*> get_all_human() {
  auto resp = c->promise("get-all-human", PRT_NULL_PKG);
}

prt::bytes _human_move(prt::bytes data) {
  human_move info;
  data.to_mem(&info, sizeof(info));
  return PRT_NORESP;
}
