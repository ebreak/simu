#ifndef __CLIENT_SERVER_H
#define __CLIENT_SERVER_H

#include <vector>
#include <object/human.h>
#include <universe.h>
#include <pyrite/client.h>

extern prt::client *c;

void init_client();
std::vector<human*> get_all_human();

#endif