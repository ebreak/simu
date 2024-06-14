#include "gl_util.h"

#include <glfw/glfw3.h>
#include <cmath>

void draw_point(float x, float y) {
  glBegin(GL_POINTS);
  glVertex2f(x, y);
  glEnd();
}

void draw_circle(float x, float y, float r) {
  const int seg = 128;
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(x, y);
  for (int i = 0; i <= seg; ++i) {
    float angle = 2.0f * M_PI * float(i) / float(seg);
    glVertex2f(r*cosf(angle)+x, r*sinf(angle)+y);
  }
  glEnd();
}
