#ifndef __CORE_COORDINATE_H
#define __CORE_COORDINATE_H

#include <mocutils/type.h>

struct polar {
  double d, angle;
};

struct coordinate {
  double x, y;
#ifdef SIMU_3D
  double z;
  coordinate(): x(0), y(0), z(0) {}
  coordinate(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
#else
  coordinate(): x(0), y(0) {}
  coordinate(double _x, double _y): x(_x), y(_y) {}
#endif
  double distance_to(const coordinate &other);
  polar polar_to(const coordinate &other);
  void operator+=(const coordinate &other);
  void operator-=(const coordinate &other);
  bool operator==(const coordinate &other);
};

#endif