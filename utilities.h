#ifndef UTILITIES
#define UTILITIES
#include <string>
#include <vector>
#include "vertexData.h"
#include "modelData.h"

class utilities {
public:
	static modelData loadVerticesFile(std::string fileName);
	
	static void printVertex(vertexData vertex);	
};


#endif
