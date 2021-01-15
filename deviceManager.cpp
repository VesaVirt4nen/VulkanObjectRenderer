#include "deviceManager.h"
#include <stdexcept>
#include <iostream>
#include <set>




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
	
	
	std::cout << "instance creation successful" << std::endl;
	if(config-> debug){
		debugmanager.setupDebugMessenger(config, &instance);
	}
}


void deviceManager::initializeDevice(configurationValues *config, windowManager* windowmanager,queueManager &queuemanager){
	if(config->debug){
		debugmanager.setupDebugManager(config);
	}
	createInstance(config, windowmanager);
	windowmanager->initializeWindow(800,600);
	windowmanager->createSurface(instance);
	pickPhysicalDevice(*windowmanager);
	createLogicalDevice(queuemanager, *windowmanager);
	
}


void deviceManager::cleanup(configurationValues *config,windowManager &windowmanager){
	
	
	if(config->debug){
		debugmanager.cleanup(instance);
	}
	vkDestroyDevice(device, nullptr);
	vkDestroySurfaceKHR(instance, *(windowmanager.getSurfacePointer()), nullptr);
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

void deviceManager::pickPhysicalDevice(windowManager &windowmanager){
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
	if (deviceCount == 0) {
		throw std::runtime_error("failed to find GPUs with Vulkan support!");
	}
	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

	for (const auto& device : devices) {
		if (isDeviceSuitable(device, windowmanager)) {
        		physicaldevice = device;
			break;
		}
	}

	if (physicaldevice == VK_NULL_HANDLE) {
		throw std::runtime_error("failed to find a suitable GPU!");
	}
}

bool deviceManager::isDeviceSuitable(VkPhysicalDevice device,windowManager &windowmanager){
	queueFamilyIndices indices = findQueueFamilies(device,windowmanager);

	return indices.graphicsFamily.has_value();
}

queueFamilyIndices deviceManager::findQueueFamilies(VkPhysicalDevice device,windowManager &windowmanager) {
	queueFamilyIndices indices;
	
	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());
	int i = 0;
	VkSurfaceKHR* surface = windowmanager.getSurfacePointer();
	for (const auto& queueFamily : queueFamilies) {
		if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
			indices.graphicsFamily = i;
		}
		VkBool32 presentSupport = false;
		vkGetPhysicalDeviceSurfaceSupportKHR(device, i, *surface, &presentSupport);
		
		if(presentSupport){
			indices.presentFamily = i;
		}

				
		if (indices.isComplete()) {
			break;
		}
		i++;
	}
	return indices;
}

VkPhysicalDevice* deviceManager::getPhysicalDevicePointer(){
	return &physicaldevice;
}

void deviceManager::createLogicalDevice(queueManager &queuemanager,windowManager &windowmanager){
	
	std::vector<VkDeviceQueueCreateInfo> queues;
	queueFamilyIndices indices = findQueueFamilies(physicaldevice,windowmanager);
	std::set<uint32_t> uniqueQueueFamilies = {indices.graphicsFamily.value(), indices.presentFamily.value()};
	for (uint32_t queueFamily : uniqueQueueFamilies){
		queues.push_back(configurationValues::populateQueueCreateInfo(queueFamily,1,1.0f));
	}
			
	VkPhysicalDeviceFeatures deviceFeatures{};
	
	VkDeviceCreateInfo createInfo{};
	createInfo = configurationValues::populateDeviceCreateInfo(&queues,&deviceFeatures);
	
	if (vkCreateDevice(physicaldevice, &createInfo, nullptr, &device) != VK_SUCCESS) {
		throw std::runtime_error("failed to create logical device!");
	}
	
	queuemanager.createGraphicsQueueHandle(device,indices);
	queuemanager.createPresentQueueHandle(device,indices);
}


