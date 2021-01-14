#ifndef CONFIGURATIONVALUES_STRUCT
#define CONFIGURATIONVALUES_STRUCT
#include <vulkan/vulkan.h>
#include <vector>
struct configurationValues{
	
	bool debug = true;
	configurationValues();
	void static populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo );
	static VkDeviceQueueCreateInfo populateQueueCreateInfo(uint32_t queueFamilyIndex,int queueCount,float priority);
	static VkDeviceCreateInfo populateDeviceCreateInfo(std::vector<VkDeviceQueueCreateInfo>* pQueueCreateInfos,VkPhysicalDeviceFeatures* pDeviceFeatures);
	const std::vector<const char*> validationLayers = {
		"VK_LAYER_KHRONOS_validation"
	};
	
	VkApplicationInfo appInfo{};
	
	VkInstanceCreateInfo instanceCreateInfo{};
	VkInstanceCreateInfo* pInstanceCreateInfo = &instanceCreateInfo;
	
	VkDebugUtilsMessengerCreateInfoEXT debugMessengerCreateInfo{};
	VkDebugUtilsMessengerCreateInfoEXT* pDebugMessengerCreateInfo;
	
	
};

#endif

