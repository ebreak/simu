#ifndef __CORE_OBJECT_DES_FUNC_H
#define __CORE_OBJECT_DES_FUNC_H

#include <object/human.h>
#include <object/astro.h>
#include <universe.h>
#include <mocutils/byte.h>

// append here to regist obj impl
static object* (*deserialize_func[])(universe*, moc::bytes) = {
  nullptr,
  human::deserialize,
  astro::deserialize,
};

#endif