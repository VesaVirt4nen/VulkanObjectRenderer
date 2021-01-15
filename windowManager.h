#ifndef WINDOWMANAGER
#define WINDOWMANAGER
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <vector>


class windowManager {

public:
	void initializeWindow(int width, int height);
	GLFWwindow* getWindowPointer();
	VkSurfaceKHR* getSurfacePointer();
	static std::vector<const char*> getRequiredExtensions();
	const char** getWindowExtensions(uint32_t *numberOfExtensions);
	void cleanup();
	void createSurface(VkInstance &instance);
	windowManager();
	
private:

	GLFWwindow* window = nullptr;
	VkSurfaceKHR surface;
	
};

#endif
