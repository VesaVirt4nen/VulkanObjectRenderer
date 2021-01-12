#ifndef DEBUGMANAGER
#define DEBUGMANAGER

#include "configurationValues.h"
class debugManager {
public:
	void setupDebugManager(configurationValues* config);
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	VkDebugUtilsMessageTypeFlagsEXT messageType,
	const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	void* pUserData);
	void cleanup(VkInstance instance);
	void setupDebugMessenger(configurationValues *config, VkInstance *instance);
private:
	bool checkLayerSupport(configurationValues *config);
	
	VkDebugUtilsMessengerEXT debugMessenger;
	
	
	
	
	
	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	
	void static DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
	
	
};


#endif
