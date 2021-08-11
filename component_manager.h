#pragma once
#include "component_array.h"
#include <shared_ptr>

namespace Shaniss::Core
{
	class ComponentManager {
		
		// this is the key to EVERYTHING, it is what it says it is
		template<typename ComponentType>
		std::shared_ptr<ComponentArray<ComponentType>> getComponentArray();
		
	};
}