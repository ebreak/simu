#ifndef __CORE_COORDINATE_H
#define __CORE_COORDINATE_H

#include <mocutils/type.h>

struct coordinate {
  double x, y;
#ifdef SIMU_3D
  double z;
  coordinate(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
#else
  coordinate(double _x, double _y): x(_x), y(_y) {}
#endif
  double distance_to(const coordinate &other);
};

#endif