#include "gl_util.h"

#include <glfw/glfw3.h>

void draw_point(float x, float y, float r) {
  glPointSize(r);
  glBegin(GL_POINTS);
  glColor3f(1, 0, 0);
  glVertex2f(x, y);
  glEnd();
}
