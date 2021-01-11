#include "deviceManager.h"
#include <stdexcept>
#include <iostream>

void deviceManager::createInstance(configurationValues *config, windowManager* windowmanager){
	
	std::cout << "instance creation started" << std::endl;
	uint32_t extensionCount = 0;
	
	const char** windowExtensions;
	
	windowExtensions = windowmanager->getWindowExtensions(&extensionCount);
	
	
	std::cout << "binding stuff started" << std::endl;
	config->createInfo.enabledExtensionCount = extensionCount;
	config->createInfo.ppEnabledExtensionNames = windowExtensions;
	config->createInfo.enabledLayerCount = 0;
	
	
	
	if(vkCreateInstance(config->pCreateInfo, nullptr, &instance)!= VK_SUCCESS) {
		throw std::runtime_error("failed to create instance");
	}
	std::cout << "instance creation successful" << std::endl;
}
void deviceManager::initializeDevice(configurationValues *config, windowManager* windowmanager){
	createInstance(config, windowmanager);
}

void deviceManager::cleanup(){
	vkDestroyInstance(instance, nullptr);
}
