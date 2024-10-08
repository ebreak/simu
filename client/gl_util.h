#ifndef __CLIENT_GL_UTIL_H
#define __CLIENT_GL_UTIL_H

#include <coordinate.h>

extern double display_scale_x, display_scale_y;
extern coordinate display_center;

#define simuabs(x) ((x) >= 0 ? (x) : (-(x)))

inline float to_gl_x(double _x) {
  return (float) (_x - display_center.x) / display_scale_x;
}

inline float to_gl_y(double _y) {
  return (float) (_y - display_center.y) / display_scale_y;
}

#define gl_color_rgb(rgb) \
  ((0xFF0000 & rgb) >> 16)/255.0, \
  ((0x00FF00 & rgb) >> 8)/255.0, \
  ((0x0000FF & rgb))/255.0

void draw_point(float x, float y);
void draw_point(double _x, double _y);
void draw_line(float _x1, float _y1, float _x2, float _y2);
void draw_line(double _x1, double _y1, double _x2, double _y2);
void draw_bar(double _x1, double _y1, double _x2, double _y2, double _width);
void draw_circle(double _x, double _y, double r);

#endif