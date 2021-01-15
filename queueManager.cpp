#include "queueManager.h"



void queueManager::createGraphicsQueueHandle(VkDevice &device,queueFamilyIndices &indices){
	vkGetDeviceQueue(device, indices.graphicsFamily.value(), 0, &graphicsQueue);

}

void queueManager::createPresentQueueHandle(VkDevice &device,queueFamilyIndices &indices){
	vkGetDeviceQueue(device, indices.presentFamily.value(), 0, &presentQueue);
}
