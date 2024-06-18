#include "gl_util.h"

#include <glfw/glfw3.h>
#include <cmath>
#include <coordinate.h>

double display_scale_x, display_scale_y;
coordinate display_center;

void draw_point(float x, float y) {
  glBegin(GL_POINTS);
  glVertex2f(x, y);
  glEnd();
}

void draw_point(double _x, double _y) {
  glBegin(GL_POINTS);
  glVertex2f(to_gl_x(_x), to_gl_y(_y));
  glEnd();
}

void draw_line(float _x1, float _y1, float _x2, float _y2) {
  glBegin(GL_LINES);
  glVertex2f(_x1, _y1);
  glVertex2f(_x2, _y2);
  glEnd();
}

void draw_line(double _x1, double _y1, double _x2, double _y2) {
  glBegin(GL_LINES);
  glVertex2f(to_gl_x(_x1), to_gl_y(_y1));
  glVertex2f(to_gl_y(_x2), to_gl_y(_y2));
  glEnd();
}

void draw_bar(double _x1, double _y1, double _x2, double _y2, double _width) {
  // 1 -> 2 -> 3 -> 4
  double dx = _x1 - _x2, dy = _y1 = _y2;
  double dist = sqrt(dx*dx + dy*dy);
  double _x4 = _x1 + dy/dist*_width;
  double _y4 = _y1 - dx/dist*_width;
  double _x3 = _x2 + dy/dist*_width;
  double _y3 = _y2 - dx/dist*_width;
  glBegin(GL_POLYGON);
  glVertex2f(to_gl_x(_x1), to_gl_y(_y1));
  glVertex2f(to_gl_x(_x2), to_gl_y(_y2));
  glVertex2f(to_gl_x(_x3), to_gl_y(_y3));
  glVertex2f(to_gl_x(_x4), to_gl_y(_y4));
  glVertex2f(to_gl_x(_x1), to_gl_y(_y1));
}

void draw_circle(double _x, double _y, double r) {
  const int seg = 128;
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(to_gl_x(_x), to_gl_y(_y));
  for (int i = 0; i <= seg; ++i) {
    float angle = 2.0f * M_PI * i / seg;
    auto x = to_gl_x(r*cosf(angle)+_x);
    auto y = to_gl_y(r*sinf(angle)+_y);
    glVertex2f(x, y);
  }
  glEnd();
}
