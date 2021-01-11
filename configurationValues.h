#ifndef CONFIGURATIONVALUES_STRUCT
#define CONFIGURATIONVALUES_STRUCT
#include <vulkan/vulkan.h>

struct configurationValues{
	
	bool debug = true;
	configurationValues();
	
	
	
	VkApplicationInfo appInfo{};	
	VkInstanceCreateInfo createInfo{};
	
	
	VkInstanceCreateInfo* pCreateInfo = &createInfo;
};

#endif

