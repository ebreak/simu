#ifndef __CLIENT_GL_UTIL_H
#define __CLIENT_GL_UTIL_H

#include <coordinate.h>

extern double display_scale_x, display_scale_y;
extern coordinate display_center;

inline float to_gl_x(double _x) {
  return (float) (_x - display_center.x) / display_scale_x;
}

inline float to_gl_y(double _y) {
  return (float) (_y - display_center.y) / display_scale_y;
}

void draw_point(float x, float y);
void draw_circle(double _x, double _y, double r);

#endif