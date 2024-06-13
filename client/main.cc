#include <GLFW/glfw3.h>
#include <stdlib.h>

int main() {
  if (!glfwInit()) exit(-1);
  GLFWwindow *window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) exit(-1);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
