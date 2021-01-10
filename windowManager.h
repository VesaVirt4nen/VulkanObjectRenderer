#ifndef WINDOWMANAGER
#define WINDOWMANAGER
#include <GLFW/glfw3.h>
#include <vector>


class windowManager {

public:
	void initializeWindow(int width, int height);
	GLFWwindow* getWindowPointer();
	static std::vector<const char*> getRequiredExtensions();
	
private:

	GLFWwindow* window;
};

#endif
