#ifndef WINDOWMANAGER
#define WINDOWMANAGER
#include <GLFW/glfw3.h>
#include <vector>


class windowManager {

public:
	void initializeWindow(int width, int height);
	GLFWwindow* getWindowPointer();
	static std::vector<const char*> getRequiredExtensions();
	const char** getWindowExtensions(uint32_t *numberOfExtensions);
	void cleanup();
	windowManager();
	
private:

	GLFWwindow* window = nullptr;
};

#endif
