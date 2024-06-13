#include "ui.h"

#include <glfw/glfw3.h>
#include <mocutils/clock.h>
#include <cstdio>

#include "gl_util.h"

void init_ui() {
  if (!glfwInit()) exit(-1);
}

void render(universe *u) {
  GLFWwindow *window = glfwCreateWindow(1024, 1024, "SIMU", NULL, NULL);
  glfwMakeContextCurrent(window);
  moc::clock start;
  printf("111\n");
  printf("%p\n", window);
  while (!glfwWindowShouldClose(window)) {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    auto ro_data = u->ro_obj();
    for (auto obj: ro_data)
      draw_point(obj->position.x, obj->position.y, 20.0f);
    glfwSwapBuffers(window);
    glfwPollEvents();
    start.tick(100);
  }
  glfwTerminate();
  exit(0);
}
