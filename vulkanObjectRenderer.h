#ifndef VULKAN_OBJECT_RENDERER
#define VULKAN_OBJECT_RENDERER
#include <vulkan/vulkan.h>
#include "windowManager.h"
#include "configurationValues.h"
#include "deviceManager.h"
#include "queueManager.h"


#include <iostream>

class vulkanObjectRenderer {

public:
	static void printTest();
	void initializeVulkan();
	void cleanup();
	
	
private:
	configurationValues config;
	VkInstance instance;
	windowManager windowmanager;
	deviceManager devicemanager;
	queueManager queuemanager;
};

#endif
