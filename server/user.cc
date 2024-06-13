#include "user.h"

#include <telecom/login.h>
#include <telecom/user.h>
#include <object/human.h>
#include <map>

#include "game.h"

u64 next_session;
std::vector<user> users;
std::map<u64, i64> session_uid;

void init_user() {
  users.push_back({0, "nahida", "akademiya", nullptr});
  moc::log("user init ok");
}

prt::bytes _login(sockaddr_in client, prt::bytes data) {
  login login_data;
  data.to_mem(&login_data, sizeof(login_data));

  i64 uid = -1;
  u64 session = -1;
  for (int i = 0; i < users.size(); ++i) {
    if (login_data.username != users[i].username)
      continue;
    if (login_data.password != users[i].password)
      continue;
    uid = i;
    break;
  }
  if (uid == -1)
    return prt::bytes(&session, sizeof(session));

  session = next_session++;
  u->insert(new human(u, coordinate()));
  session_uid[session] = uid;
  return prt::bytes(&session, sizeof(session));
}
