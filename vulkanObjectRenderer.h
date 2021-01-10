#ifndef VULKAN_OBJECT_RENDERER
#define VULKAN_OBJECT_RENDERER
#include <vulkan/vulkan.h>
#include "windowManager.h"
#include <iostream>

class vulkanObjectRenderer {

public:
	static void printTest();
	void initializeVulkan();
	
private:
	VkInstance instance;
	windowManager windowmanager;

};

#endif
