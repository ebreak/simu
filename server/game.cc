#include "game.h"

#include <universe.h>
#include <object/human.h>
#include <object/astro.h>

#include "user.h"

universe *u;

void start() {
  u = new universe;
  u->start();
}

prt::bytes _get_universe(sockaddr_in client, prt::bytes data) {
  return u->serialize();
}

prt::bytes _human_move(sockaddr_in client, prt::bytes data) {
  u64 session;
  data.range(0, 8).to_mem(&session, sizeof(session));
  coordinate delta;
  data.range(8, data.size()).to_mem(&delta, sizeof(delta));
  i64 uid = session_uid[session];
  u64 oid = uid_oid[uid];
  auto ho = u->operator[](oid);
  human *h = (human*) ho;
  h->velocity = delta;

  prt::bytes broadcast(&oid, sizeof(oid));
  broadcast += data.range(8, data.size());
  tell_all("human-move", broadcast);
  return PRT_NULL_PKG;
}
