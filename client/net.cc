#include "net.h"

#include <pyrite/client.h>
#include <object/human.h>
#include <object/astro.h>
#include <object/deserialize_func.h>

#include "game.h"

prt::client *c;
u64 session;

prt::bytes _update_object(prt::bytes data);
prt::bytes _human_move(prt::bytes data);

void init_client(std::string username, std::string password) {
  c = new prt::client("127.0.0.1", 8082);
  c->set_handler("human-move", _human_move);
  c->set_handler("update-object", _update_object);
  c->async();

  prt::bytes login_data;
  login_data += username;
  login_data += password;
  auto resp = c->promise("login", login_data);
  resp.to_mem(&session, sizeof(session));
  if (session == -1)
    moc::panic("invalid username or password");
  moc::logf("login success. session: %llx\n", session);
}

prt::bytes _update_object(prt::bytes data) {
  if (u == nullptr) return PRT_NORESP;

  bool active;
  data.to_mem(&active, sizeof(active));
  data.ptr += sizeof(active);

  int kind = data.next_int32();
  object *obj = nullptr;

  if (kind >= sizeof(deserialize_func)/sizeof(void*))
    moc::panicf("invalid obj type: %d\n", kind);
  obj = deserialize_func[kind](u, data.range(data.ptr, data.size()));

  u->update(obj->id, obj, active);
  return PRT_NORESP;
}

prt::bytes _human_move(prt::bytes data) {
  u64 oid;
  data.range(0, 8).to_mem(&oid, sizeof(oid));
  coordinate delta;
  data.range(8, data.size()).to_mem(&delta, sizeof(delta));

  auto ho = const_cast<object*>(u->operator[](oid));
  human *h = static_cast<human*>(ho);
  h->velocity = delta;
  return PRT_NORESP;
}
