#include "user.h"

#include <telecom/user.h>
#include <object/human.h>
#include <map>

#include "game.h"

u64 next_session;
std::vector<user> users;
std::map<u64, i64> session_uid;
std::map<i64, u64> uid_oid;

void init_user() {
  users.push_back({0, "nahida", "akademiya", nullptr});
  moc::log("user init ok");
}

prt::bytes _login(sockaddr_in client, prt::bytes data) {
  std::string username = data.next_string();
  std::string password = data.next_string();

  i64 uid = -1;
  u64 session = -1;
  for (int i = 0; i < users.size(); ++i) {
    if (username != users[i].username)
      continue;
    if (password != users[i].password)
      continue;
    uid = i;
    break;
  }
  if (uid == -1)
    return prt::bytes(&session, sizeof(session));

  session = next_session++;
  session_uid[session] = uid;

  if (uid_oid.count(uid))
    return prt::bytes(&session, sizeof(session));
  uid_oid[uid] = u->insert(new human(u, coordinate()));
  return prt::bytes(&session, sizeof(session));
}
