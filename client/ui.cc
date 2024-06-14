#include "ui.h"

#include <glfw/glfw3.h>
#include <mocutils/clock.h>
#include <cstdio>

#include "gl_util.h"
#include "game.h"
#include "net.h"

vector my_velocity;

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

void render(GLFWwindow *window) {
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);
  auto ro_data = u->ro_obj();
  for (auto obj: ro_data)
    draw_point(obj->position.x / 4, obj->position.y / 4, 20.0f);
  glfwSwapBuffers(window);
}

void ui_mainloop() {
  while (!u) ;

  // glfw init
  if (!glfwInit()) exit(-1);
  GLFWwindow *window = glfwCreateWindow(1024, 1024, "SIMU", NULL, NULL);
  glfwMakeContextCurrent(window);
  glfwSetKeyCallback(window, key_callback);

  moc::clock start;
  while (!glfwWindowShouldClose(window)) {
    render(window);
    glfwPollEvents();
    start.tick(10);
  }

  glfwTerminate();
  exit(0);
}
