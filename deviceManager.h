#ifndef DEVICEMANAGER
#define DEVICEMANAGER
#include <vulkan/vulkan.h>
#include "configurationValues.h"
#include "debugManager.h"
#include "windowManager.h"
#include "queueFamilyIndices.h"
#include "queueManager.h"
#include <vector>

class deviceManager {
public:
	void initializeDevice(configurationValues *config, windowManager *windowmanager,queueManager &queuemanager);
	VkInstance* getInstancePointer();
	VkPhysicalDevice* getPhysicalDevicePointer();
	VkDevice* getLogicalDevicePointer();
	void cleanup(configurationValues *config, windowManager &windowmanager);
	
private:
	void pickPhysicalDevice(windowManager &windowmanager);
	void createInstance(configurationValues *config, windowManager *windowmanager);
	bool isDeviceSuitable(VkPhysicalDevice device,windowManager &windowmanager);
	queueFamilyIndices findQueueFamilies(VkPhysicalDevice device, windowManager &windowmanager);
	void createDebugManager();
	void createLogicalDevice(queueManager &queuemanager, windowManager &windowmanager);
	
	std::vector<const char*> getRequiredExtensions(windowManager* windowmanager,configurationValues *config);
	
	debugManager debugmanager;
	VkInstance instance;
	VkPhysicalDevice physicaldevice = VK_NULL_HANDLE;
	VkDevice device;
	
};
#endif
