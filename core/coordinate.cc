#include "coordinate.h"

#include <cmath>

inline double square(double x) {
  return x*x;
}

i64 coordinate::distance_to(const coordinate &other) {
  double sum = square(other.x - this->x) 
    + square(other.y - this->y);
#ifdef SIMU_3D
  sum += square(other.z - this->z);
#endif
  return sqrt(sum);
}
