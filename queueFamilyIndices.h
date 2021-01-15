#ifndef QUEUEFAMILYINDICES_STRUCT
#define QUEUEFAMILYINDICES_STRUCT
#include <optional>
struct queueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;
	
	bool isComplete(){
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};

#endif
