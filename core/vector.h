#ifndef __CORE_VECTOR_H
#define __CORE_VECTOR_H

#include <cmath>

#include <coordinate.h>

struct vector: coordinate {
#ifdef SIMU_3D
  double z;
  vector(): x(0), y(0), z(0) {}
  vector(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
#else
  vector(): coordinate(0, 0) {}
  vector(double _x, double _y): coordinate(_x, _y) {}
#endif

  vector(polar p) {
    this->x = p.d * cos(p.angle);
    this->y = p.d * sin(p.angle);
  }

  void operator=(coordinate other) {
    this->x = other.x;
    this->y = other.y;
#ifdef SIMU_3D
    ret.z = other.z;
#endif
  }

  vector operator/(double d) {
    vector ret = *this;
    ret.x /= d;
    ret.y /= d;
#ifdef SIMU_3D
    ret.z /= d;
#endif
    return ret;
  }
};

#endif