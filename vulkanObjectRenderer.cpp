
#include "vulkanObjectRenderer.h"
#include <stdexcept>
#include <vector>

void vulkanObjectRenderer::printTest(){

	std::cout << "testing separate file!" << std::endl;
	return;

}

void vulkanObjectRenderer::initializeVulkan(){
	
	
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Vulkan object renderer";
	appInfo.applicationVersion = VK_MAKE_VERSION(1,0,0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1,0,0);
	appInfo.apiVersion = VK_API_VERSION_1_0;
	
	
	
	
	VkInstanceCreateInfo createInfo;
	
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pNext = nullptr;
	createInfo.flags = 0;
	createInfo.pApplicationInfo = &appInfo;
	
	
	
	//if(vkCreateInstance(&createInfo,nullptr, &instance) != VK_SUCCESS){
	//	throw std::runtime_error("failed to create instance");
	//}

}
