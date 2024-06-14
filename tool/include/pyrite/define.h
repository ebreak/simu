#ifndef _PRT_DEFINE_H
#define _PRT_DEFINE_H

#include <mocutils/byte.h>
#include <mocutils/type.h>

#define assert(expr) if (!expr) exit(1);

#define PRT_NORESP   moc::bytes()
#define PRT_NULL_PKG moc::bytes()

namespace prt {
  const int max_transmit_size = 1024;
  typedef moc::byte byte;
  typedef moc::bytes bytes;
  enum connection_state {
    closed,
    established,
  };
}

#endif