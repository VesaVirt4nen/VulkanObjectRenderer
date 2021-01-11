#include <iostream>
#include <exception>
#include "vulkanObjectRenderer.h"
#include "utilities.h"
#include "vertexData.h"
#include "modelData.h"
#include "windowManager.h"
#include <vector>
void testLoadFiles(){
	modelData model;
	
	try {
		 model = utilities::loadVerticesFile("test.obj");
	
	} catch (const std::exception& e)  {
		std::cout << e.what() << std::endl;
	
	}
	
	std::cout << model.vertices.size() << std::endl;
	utilities::printVertex(model.vertices[0]);


}

void testWindow(){
	windowManager windowmanager;
	windowmanager.initializeWindow(800,600);
	GLFWwindow* window = windowmanager.getWindowPointer();
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
	windowmanager.cleanup();
}

void testInstance(){
	vulkanObjectRenderer renderer;
	renderer.initializeVulkan();
	renderer.cleanup();
}


int main() {

	std::cout << "TESTING!" << std::endl;
	vulkanObjectRenderer::printTest();
	testLoadFiles();
	testInstance();
	testWindow();
	return 0;
	
}



