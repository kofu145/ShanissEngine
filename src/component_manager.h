#pragma once
#include "component_collection.h"
#include <unordered_map>
#include <memory>

namespace ShanissCore
{

	
	template<class T>
	class Deleter;

	// TODO: make this a singleton so that we can access it for our entity methods

	// A singleton that manages all the ComponentCollections
	class ComponentManager {
		

		public:

			friend class Deleter<ComponentManager>;


			using componentManagerPtr = std::unique_ptr<ComponentManager, Deleter<ComponentManager>>;

			static ComponentManager* getInstance();

			void clear();

			
			template<typename ComponentType>
			ComponentCollection<ComponentType> getComponentArray();

	

		private:

			static std::unique_ptr<ComponentManager, Deleter<ComponentManager>> instance;

			// please work
			//ComponentManager (const ComponentManager&) = delete;
			//ComponentManager& operator = (const ComponentManager&) = delete;

			// Private constructor so no objects can be created, use getinstance
			ComponentManager();
			~ComponentManager();
			


			// store all the component arrays for every type
			// note: MUST store pointers of base derived class

			// if efficiency issues regarding this, replace type_info with char and change up all key def
			std::unordered_map<const char*, std::shared_ptr<IComponentCollection>> componentCollections;


	};



	template<class T>
	class Deleter
	{


		// making the operator private doesn't work even with this friend and idk why :(
		friend ComponentManager::componentManagerPtr;
		
		public:
			void operator()(T* t) { delete t; };

	};

}