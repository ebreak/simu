#include "user.h"

#include <telecom/login.h>
#include <telecom/user.h>

u64 next_session;
std::vector<user> users;

void init_user() {
  users.push_back({0, "nahida", "akademiya"});
  moc::log("user init ok");
}

prt::bytes _login(sockaddr_in client, prt::bytes data) {
  login login_data;
  data.to_mem(&login_data, sizeof(login_data));
  u64 session = next_session++;
  return prt::bytes(&session, sizeof(session));
}
