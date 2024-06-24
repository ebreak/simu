#ifndef __CORE_OBJECT_DES_FUNC_H
#define __CORE_OBJECT_DES_FUNC_H

#include <mocutils/byte.h>
#include <config.h>

struct object;
struct universe;

static object* (*deserialize_func[MAX_OBJ_NUM])(universe*, moc::bytes) = {};

#endif