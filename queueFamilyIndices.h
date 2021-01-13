#ifndef QUEUEFAMILYINDICES_STRUCT
#define QUEUEFAMILYINDICES_STRUCT
#include <optional>
struct queueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	
	bool isComplete(){
		return graphicsFamily.has_value();
	}
};

#endif
