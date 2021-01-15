
#include "vulkanObjectRenderer.h"
#include <stdexcept>
#include <vector>

void vulkanObjectRenderer::printTest(){

	std::cout << "testing separate file!" << std::endl;
	return;

}

void vulkanObjectRenderer::initializeVulkan(){
	
	devicemanager.initializeDevice(&config, &windowmanager,queuemanager);
	
}

void vulkanObjectRenderer::cleanup(){

	devicemanager.cleanup(&config,windowmanager);
	windowmanager.cleanup();
}
