#ifndef __SERVER_USER_H
#define __SERVER_USER_H

#include <mocutils/type.h>
#include <pyrite/server.h>
#include <telecom/user.h>

extern std::vector<user> users;
extern std::map<u64, i64> session_uid;
extern std::map<i64, u64> uid_oid;

void init_user();
void tell_all(std::string identifier, prt::bytes data);
prt::bytes _login(sockaddr_in client, prt::bytes data);

#endif