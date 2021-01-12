#ifndef DEVICEMANAGER
#define DEVICEMANAGER
#include <vulkan/vulkan.h>
#include "configurationValues.h"
#include "debugManager.h"
#include "windowManager.h"
#include <vector>

class deviceManager {
public:
	void initializeDevice(configurationValues *config, windowManager *windowmanager);
	VkInstance* getInstancePointer();
	VkPhysicalDevice* getPhysicalDevicePointer();
	VkDevice* getLogicalDevicePointer();
	void cleanup(configurationValues *config);
	
private:
	void pickPhysicalDevice();
	void createInstance(configurationValues *config, windowManager *windowmanager);
	
	void createDebugManager();
	void createLogicalDevice();
	
	std::vector<const char*> getRequiredExtensions(windowManager* windowmanager,configurationValues *config);
	
	debugManager debugmanager;
	VkInstance instance;

};
#endif
