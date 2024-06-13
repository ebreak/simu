#ifndef __SERVER_USER_H
#define __SERVER_USER_H

#include <mocutils/type.h>
#include <pyrite/server.h>

void init_user();
prt::bytes _login(sockaddr_in client, prt::bytes data);

#endif