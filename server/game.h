#ifndef __SERVER_GAME_H
#define __SERVER_GAME_H

#include <universe.h>
#include <pyrite/define.h>
#include <pyrite/server.h>

extern universe *u;

void start();
prt::bytes _get_universe(sockaddr_in client, prt::bytes data);
prt::bytes _human_move(sockaddr_in client, prt::bytes data);

#endif