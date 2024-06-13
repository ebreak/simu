#include "coordinate.h"

#include <cmath>

inline double square(double x) {
  return x*x;
}

double coordinate::distance_to(const coordinate &other) {
  double sum = square(other.x - this->x) 
    + square(other.y - this->y);
#ifdef SIMU_3D
  sum += square(other.z - this->z);
#endif
  return sqrt(sum);
}

void coordinate::operator+=(const coordinate &other) {
  this->x += other.x;
  this->y += other.y;
#ifdef SIMU_3D
  this->z += other.z;
#endif
}

bool coordinate::operator==(const coordinate &other) {
  if (this->x != other.x) return false;
  if (this->y != other.y) return false;
#ifdef SIMU_3D
  if (this->z != other.z) return false;
#endif
  return true;
}
