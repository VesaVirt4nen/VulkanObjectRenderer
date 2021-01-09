#include "utilities.h"
#include "modelData.h"
#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"
#include <unordered_map>
#include <iostream>



modelData utilities::loadVerticesFile(std::string fileName){
	
	std::vector<vertexData> vertices;
	std::vector<uint32_t> indices;
	
	modelData model;
	
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;
	std::string warn, err;
	
	if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, fileName.c_str())) {
		throw std::runtime_error(warn + err);
	}
	
	std::unordered_map<vertexData, uint32_t> uniqueVertices{};
	
	for (const auto& shape : shapes) {
		for (const auto& index : shape.mesh.indices) {
        		vertexData vertex{};
        		
        		vertex.pos = {
				attrib.vertices[3 * index.vertex_index + 0],
				attrib.vertices[3 * index.vertex_index + 1],
				attrib.vertices[3 * index.vertex_index + 2]
			};

			vertex.texCoord = {
				attrib.texcoords[2 * index.texcoord_index + 0],
				attrib.texcoords[2 * index.texcoord_index + 1]
			};

			vertex.color = {1.0f, 1.0f, 1.0f};
        		

			vertices.push_back(vertex);
			if (uniqueVertices.count(vertex) == 0) {
				uniqueVertices[vertex] = static_cast<uint32_t>(vertices.size());
				vertices.push_back(vertex);
			}

			indices.push_back(uniqueVertices[vertex]);
		}	
	}
	
	model.vertices = vertices;
	model.indices = indices;
	
	return model;
}


void utilities::printVertex(vertexData vertex){
	std::cout << vertex.pos.x << "  " << vertex.pos.y << "  " << vertex.pos.z << std::endl;
	return;
}

