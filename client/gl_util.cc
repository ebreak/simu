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
