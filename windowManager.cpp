#include "windowManager.h"
#include <iostream>
windowManager::windowManager(){
	glfwInit();
}

void windowManager::initializeWindow(int width, int height){
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        window = glfwCreateWindow(width, height, "Vulkan", nullptr, nullptr);
        glfwSetWindowUserPointer(window, this);
}

GLFWwindow* windowManager::getWindowPointer(){
	return window;

}

const char** windowManager::getWindowExtensions(uint32_t* numberOfExtensions) {
	std::cout << "getting window extensions" << std::endl;

	return glfwGetRequiredInstanceExtensions(numberOfExtensions);
}

void windowManager::cleanup(){
	std::cout << "window cleanup starting" << std::endl;
	if(window != nullptr) {glfwDestroyWindow(window);}
	std::cout << "window termination" << std::endl;
	glfwTerminate();
}


void windowManager::createSurface(VkInstance &instance){
	if(glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS) {
		throw std::runtime_error("failed to create window surface!");
	}
}

VkSurfaceKHR* windowManager::getSurfacePointer(){
	return &surface;
}
