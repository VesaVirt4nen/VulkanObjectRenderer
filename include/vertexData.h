#ifndef VERTEXDATA
#define VERTEXDATA

#include <glm.hpp>

struct vertexData {
public:
	vec3 pos;
	vec2 texCoord;
	vec3 color;
	
	bool operator==(const Vertex& other) const {
		return pos == other.pos && color == other.color && texCoord == other.texCoord;
	}
};


#endif
