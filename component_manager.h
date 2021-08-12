#pragma once
#include "component_collection.h"
#include <unordered_map>
#include <memory>

namespace ShanissCore
{
	// TODO: make this a singleton so that we can access it for our entity methods
	class ComponentManager {
		
		public:
			// this is the key to EVERYTHING, it is what it says it is
			template<typename ComponentType>
			ComponentCollection<ComponentType> getComponentArray();

		private:
			// store all the component arrays for every type
			// note: MUST store pointers of base derived class

			// if efficiency issues regarding this, replace type_info with char and change up all key def
			std::unordered_map<std::type_info, std::shared_ptr<IComponentCollection>> componentCollections;


	};
}