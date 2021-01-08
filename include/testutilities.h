#ifndef TEST_UTILITIES
#define TEST_UTILITIES

#include <vector>
#include "vertexData.h"

class TestUtilities {
public:
	static std::vector<vertexData> loadVerticesFile(char[] fileName);
	
	static void printVertex(vertexData vertex);	
};


#endif
