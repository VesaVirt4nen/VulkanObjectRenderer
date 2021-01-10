#include "windowManager.h"

void windowManager::initializeWindow(int width, int height){
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        window = glfwCreateWindow(width, height, "Vulkan", nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
}

GLFWwindow* windowManager::getWindowPointer(){
	return window;

}
