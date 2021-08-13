#pragma once
#include "component_collection.h"
#include <unordered_map>
#include <memory>

namespace ShanissCore
{
	// TODO: make this a singleton so that we can access it for our entity methods
	class ComponentManager {
		
		public:

			static ComponentManager* getInstance();

			void clear();

			
			template<typename ComponentType>
			ComponentCollection<ComponentType> getComponentArray();



		private:

			static std::unique_ptr<ComponentManager> instance;

			ComponentManager(const ComponentManager& arg) = delete;					// Copy constructor
			ComponentManager(const ComponentManager&& arg) = delete;				// Move constructor
			ComponentManager& operator=(const ComponentManager& arg) = delete;		// Assignment operator
			ComponentManager& operator=(const ComponentManager&& arg) = delete;		// Move operator

			// Private constructor so no objects can be created, use getinstance
			ComponentManager();
			~ComponentManager();

			


			// store all the component arrays for every type
			// note: MUST store pointers of base derived class

			// if efficiency issues regarding this, replace type_info with char and change up all key def
			std::unordered_map<std::type_info, std::shared_ptr<IComponentCollection>> componentCollections;


	};
}