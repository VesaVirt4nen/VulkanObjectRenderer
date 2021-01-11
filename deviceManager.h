#ifndef DEVICEMANAGER
#define DEVICEMANAGER
#include <vulkan/vulkan.h>
#include "configurationValues.h"
#include "debugManager.h"
#include "windowManager.h"

class deviceManager {
public:
	void initializeDevice(configurationValues *config, windowManager *windowmanager);
	VkInstance* getInstancePointer();
	VkPhysicalDevice* getPhysicalDevicePointer();
	VkDevice* getLogicalDevicePointer();
	
	void cleanup();
	
private:
	void pickPhysicalDevice();
	void createInstance(configurationValues *config, windowManager *windowmanager);
	
	void createDebugManager();
	void createLogicalDevice();
	
	
	
	//debugManager debugmanager;
	VkInstance instance;

};
#endif
