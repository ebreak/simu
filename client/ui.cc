#include "ui.h"

#include <glfw/glfw3.h>
#include <mocutils/clock.h>
#include <cstdio>
#include <config.h>

#include "gl_util.h"
#include "game.h"
#include "net.h"

vector my_velocity;

bool in_display_range(coordinate point) {
  if (simuabs(point.x-display_center.x) >= display_scale_x)
    return false;
  if (simuabs(point.y-display_center.y) >= display_scale_y)
    return false;
  return true;
}

void key_callback(
  GLFWwindow *window, int key, 
  int scancode, int action, int mods
) {
  prt::bytes data(&session, sizeof(session));
  switch (action) {
  case GLFW_PRESS:
    if (key == GLFW_KEY_W)
      my_velocity.y += 1.0/32;
    else if (key == GLFW_KEY_A)
      my_velocity.x += -1.0/32;
    else if (key == GLFW_KEY_S)
      my_velocity.y += -1.0/32;
    else if (key == GLFW_KEY_D)
      my_velocity.x += 1.0/32;
    data += prt::bytes(&my_velocity, sizeof(vector));
    c->tell("human-move", data);
    break;
  case GLFW_RELEASE:
    if (key == GLFW_KEY_W)
      my_velocity.y -= 1.0/32;
    else if (key == GLFW_KEY_A)
      my_velocity.x -= -1.0/32;
    else if (key == GLFW_KEY_S)
      my_velocity.y -= -1.0/32;
    else if (key == GLFW_KEY_D)
      my_velocity.x -= 1.0/32;
    data += prt::bytes(&my_velocity, sizeof(vector));
    c->tell("human-move", data);
    break;
  }
}

void render_toolbar() {

}

void render(GLFWwindow *window) {
  glClearColor(gl_color_rgb(0x333333), 0);
  glClear(GL_COLOR_BUFFER_BIT);
  auto ro_data = u->ro_obj();
  for (auto obj: ro_data) {
    if (!in_display_range(obj->position)) continue;
    glColor3f(1.0f, 215.0f/225, 0.0f);
    draw_circle(obj->position.x, obj->position.y, 1.0/8);
  }
  glfwSwapBuffers(window);
}

void ui_mainloop() {
  while (!u) ;

  // glfw init
  if (!glfwInit()) exit(-1);
  auto monitor = glfwGetPrimaryMonitor();
  auto mode = glfwGetVideoMode(monitor);
  u64 display_width, display_height;
  display_width = mode->width;
  display_height = mode->height;
  GLFWwindow *window = glfwCreateWindow(display_width, display_height, "SIMU", monitor, NULL);
  glfwMakeContextCurrent(window);
  glfwFocusWindow(window);
  glfwSetKeyCallback(window, key_callback);

  // render range init
  display_center = init_display_center;
  display_scale_x = init_display_scale;
  display_scale_y = display_scale_x*display_height/display_width;

  moc::clock start;
  while (!glfwWindowShouldClose(window)) {
    render(window);
    glfwPollEvents();
    start.tick(1000 / mode->refreshRate);
  }

  glfwTerminate();
  exit(0);
}
