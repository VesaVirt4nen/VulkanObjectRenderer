#include "deviceManager.h"
#include <stdexcept>
#include <iostream>


void deviceManager::createInstance(configurationValues* config, windowManager* windowmanager){
	
	std::cout << "instance creation started" << std::endl;
	
	std::vector<const char*> extensions = getRequiredExtensions(windowmanager,config);
	
	config->pInstanceCreateInfo->enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	config->pInstanceCreateInfo->ppEnabledExtensionNames = extensions.data();
	
	VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo;
	if (config->debug) {
		config->pInstanceCreateInfo->enabledLayerCount = static_cast<uint32_t>(config->validationLayers.size());
		config->pInstanceCreateInfo->ppEnabledLayerNames = config->validationLayers.data();
		configurationValues::populateDebugMessengerCreateInfo(debugCreateInfo);
		debugCreateInfo.pfnUserCallback = debugManager::debugCallback;
		config->pInstanceCreateInfo->pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &debugCreateInfo;
		
		
		
	} else {
		config->pInstanceCreateInfo->enabledLayerCount = 0;
		
		config->pInstanceCreateInfo->pNext = nullptr;
	}
	
	
	
	if(vkCreateInstance(config->pInstanceCreateInfo, nullptr, &instance)!= VK_SUCCESS) {
		throw std::runtime_error("failed to create instance");
	}
	
	if(config-> debug){
		debugmanager.setupDebugMessenger(config, &instance);
	}
	std::cout << "instance creation successful" << std::endl;
}


void deviceManager::initializeDevice(configurationValues *config, windowManager* windowmanager){
	if(config->debug){
		debugmanager.setupDebugManager(config);
	}
	createInstance(config, windowmanager);
	
}


void deviceManager::cleanup(configurationValues *config){
	if(config->debug){
		debugmanager.cleanup(instance);
	}
	vkDestroyInstance(instance, nullptr);
}

std::vector<const char*> deviceManager::getRequiredExtensions(windowManager* windowmanager,configurationValues *config) {

	std::cout << "checking extensions" << std::endl;
	uint32_t windowExtensionCount = 0;
	
	const char** windowExtensions;
	
	windowExtensions = windowmanager->getWindowExtensions(&windowExtensionCount);
	
	std::vector<const char*> extensions(windowExtensions, windowExtensions + windowExtensionCount);
	if(config->debug){
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}
	return extensions;
}
