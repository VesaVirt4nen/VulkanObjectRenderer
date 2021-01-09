#ifndef VERTEXDATA
#define VERTEXDATA

#include <glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>

struct vertexData {
public:
	glm::vec3 pos;
	glm::vec2 texCoord;
	glm::vec3 color;
	
	bool operator==(const vertexData& other) const {
		return pos == other.pos && color == other.color && texCoord == other.texCoord;
	}
};

namespace std {
	template<> struct hash<vertexData> {
		size_t operator()(vertexData const& vertex) const {
			return ((hash<glm::vec3>()(vertex.pos) ^
				(hash<glm::vec3>()(vertex.color) << 1)) >> 1) ^
				(hash<glm::vec2>()(vertex.texCoord) << 1);
		}
	};
}

#endif
