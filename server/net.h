#ifndef __SERVER_NET_H
#define __SERVER_NET_H

#include <pyrite/server.h>
#include <object.h>

extern prt::server *s;

void init_server();
void update_object(object *obj, bool active);

#endif