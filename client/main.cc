#include <GLFW/glfw3.h>
#include <cstdio>
#include <thread>

#include <universe.h>
#include <object/human.h>
#include <mocutils/clock.h>

void render(universe *u) {
  if (!glfwInit()) exit(-1);
  GLFWwindow *window = glfwCreateWindow(1024, 1024, "SIMU", NULL, NULL);
  glfwMakeContextCurrent(window);
  moc::clock start;
  while (!glfwWindowShouldClose(window)) {
    auto ro_data = u->ro_obj();
    glfwPollEvents();
    start.tick(100);
  }
  glfwTerminate();
  exit(0);
}

int main() {
  universe u;
  auto id = u.insert(new human(&u, coordinate(0, 0)));
  u.activate(id);
  std::thread render_thread(render, &u);
  u.start(100, false);
  return 0;
}
