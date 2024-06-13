#include "ui.h"

#include <glfw/glfw3.h>
#include <mocutils/clock.h>
#include <cstdio>

#include "gl_util.h"
#include "game.h"
#include "net.h"

void process_key(GLFWwindow *window) {
  coordinate delta;
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    delta = coordinate(0, 1.0/32);
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    delta = coordinate(-1.0/32, 0);
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    delta = coordinate(0, -1.0/32);
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    delta = coordinate(1.0/32, 0);
  prt::bytes data(&session, sizeof(session));
  data += prt::bytes(&delta, sizeof(coordinate));
  c->tell("human-move", data);;
}

void render(GLFWwindow *window) {
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);
  auto ro_data = u->ro_obj();
  for (auto obj: ro_data)
    draw_point(obj->position.x, obj->position.y, 20.0f);
  glfwSwapBuffers(window);
}

void ui_mainloop() {
  while (!u) ;

  if (!glfwInit()) exit(-1);
  GLFWwindow *window = glfwCreateWindow(1024, 1024, "SIMU", NULL, NULL);
  glfwMakeContextCurrent(window);

  moc::clock start;
  while (!glfwWindowShouldClose(window)) {
    process_key(window);
    render(window);
    glfwPollEvents();
    start.tick(10);
  }

  glfwTerminate();
  exit(0);
}
