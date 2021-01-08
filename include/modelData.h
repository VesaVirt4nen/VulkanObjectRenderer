#ifndef MODEL_DATA
#define MODEL_DATA

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <vector>



class modelData{
public:
	std::vector<vertexData> vertices;
	std::vector<uint32_t> indices;
	int texHeight, texWidth, texChannels;
	stbi_uc pixels;
	
	void loadModel();
	
	void loadTexture();
};


#endif
