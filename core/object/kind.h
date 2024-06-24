#ifndef __CORE_OBJECT_KIND_H
#define __CORE_OBJECT_KIND_H

#include <mocutils/type.h>

// append here to regist obj impl
// no more than config.h:MAX_OBJ_NUM
enum object_kind {
  obj_human = 1,
  obj_astro,
};

#endif