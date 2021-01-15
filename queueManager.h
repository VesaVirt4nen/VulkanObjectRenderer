#ifndef QUEUEMANAGER
#define QUEUEMANAGER
#include <vulkan/vulkan.h>
#include "queueFamilyIndices.h"

class queueManager {
public:
	VkQueue* getGraphicsQueuePointer();
	VkQueue* getPresentQueuePointer();
	void createGraphicsQueueHandle(VkDevice &device,queueFamilyIndices &indices);
	void createPresentQueueHandle(VkDevice &device,queueFamilyIndices &indices);

private:
	VkQueue graphicsQueue;
	VkQueue presentQueue;
};

#endif
