
#include "vulkanObjectRenderer.h"
#include <stdexcept>
#include <vector>

void vulkanObjectRenderer::printTest(){

	std::cout << "testing separate file!" << std::endl;
	return;

}

void vulkanObjectRenderer::initializeVulkan(){
	
	devicemanager.initializeDevice(&config, &windowmanager);
	

}

void vulkanObjectRenderer::cleanup(){

	std::cout << "starting cleanup" << std::endl;
	devicemanager.cleanup();
	windowmanager.cleanup();
	std::cout << "cleanup succesful" << std::endl;
}
