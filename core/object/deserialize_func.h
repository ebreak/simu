#ifndef __CORE_OBJECT_DES_FUNC_H
#define __CORE_OBJECT_DES_FUNC_H

#include <mocutils/byte.h>

struct object;
struct universe;

static object* (*deserialize_func[128])(universe*, moc::bytes) = {};

#endif