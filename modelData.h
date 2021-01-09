#ifndef MODELDATA
#define MODELDATA

#include <stb_image.h>


#include <string>
#include <vector>
#include "vertexData.h"


class modelData{
public:
	std::vector<vertexData> vertices;
	std::vector<uint32_t> indices;
	int texHeight, texWidth, texChannels;
	stbi_uc* pixels;
	
	void bindTextureFile(std::string fileName);
};


#endif
