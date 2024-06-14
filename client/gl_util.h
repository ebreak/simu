#ifndef __CLIENT_GL_UTIL_H
#define __CLIENT_GL_UTIL_H

#include <coordinate.h>

extern double display_range_x, display_range_y;
extern coordinate display_start;

inline float to_gl_x(double _x) {
  double x = (_x - display_start.x) / display_range_x;
  x = 2*x-1;
  return (float) x;
}

inline float to_gl_y(double _y) {
  double y = (_y - display_start.y) / display_range_y;
  y = 2*y-1;
  return (float) y;
}

void draw_point(float x, float y);
void draw_circle(double _x, double _y, double r);

#endif