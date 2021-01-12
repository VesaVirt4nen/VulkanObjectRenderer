#include "debugManager.h"
#include <cstring>
#include <stdexcept>
#include <iostream>



bool debugManager::checkLayerSupport(configurationValues* config){

	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : config->validationLayers) {
		bool layerFound = false;

		for (const auto& layerProperties : availableLayers) {
			if (strcmp(layerName, layerProperties.layerName) == 0) {
				layerFound = true;
				break;
			}
		}

		if (!layerFound) {
			return false;
		}
	}

	return true;
}
	
void debugManager::setupDebugManager(configurationValues* config){
	if (!checkLayerSupport(config)) {
		throw std::runtime_error("validation layers requested, but not available!");
	}
	
	config->pInstanceCreateInfo->enabledLayerCount = static_cast<uint32_t>(config->validationLayers.size());
	config->pInstanceCreateInfo->ppEnabledLayerNames = config->validationLayers.data();
}	


VKAPI_ATTR VkBool32 VKAPI_CALL debugManager::debugCallback(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	VkDebugUtilsMessageTypeFlagsEXT messageType,
	const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
	void* pUserData) {

	std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;

	return VK_FALSE;
}

void debugManager::setupDebugMessenger(configurationValues *config,VkInstance *instance){
	config->pDebugMessengerCreateInfo->pfnUserCallback = debugCallback;
	
	if (CreateDebugUtilsMessengerEXT(*instance, config->pDebugMessengerCreateInfo, nullptr, &debugMessenger) != VK_SUCCESS) {
		throw std::runtime_error("failed to set up debug messenger!");
	}
}

VkResult debugManager::CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger) {
	auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, 			"vkCreateDebugUtilsMessengerEXT");
	if (func != nullptr) {
		return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
	} else {
		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}
}

void debugManager::DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator){
	auto func = (PFN_vkDestroyDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance, 				"vkDestroyDebugUtilsMessengerEXT");
	if (func != nullptr) {
		func(instance, debugMessenger, pAllocator);
	}
}

void debugManager::cleanup(VkInstance instance){
	DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
}

