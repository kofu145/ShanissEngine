#include "component_collection.h"
#include <unordered_map>

namespace ShanissCore {

	template<class T>
	T& ComponentCollection<T>::getData(int entityID)
	{
		assert(!this->hasEntity(entityID) && "Attempting to retrieve non-existant component!");

		// give a reference to component owned by said entity
		return components[entityID];
	}

	template<class T>
	void ComponentCollection<T>::insertData(int entityID, T component) {

		assert(this->hasEntity(entityID) && "Attempting to add component to same entity more than once!");
		components.insert({entityID, component});

	}

	template<class T>
	void ComponentCollection<T>::removeData(int entityID) {

		assert(!this->hasEntity(entityID) && "Attempting to remove non-existant component!");

		// Don't need to do index moving shenanigans because it's an unordered_map, entity id management
		// is also handled elsewhere.


		// suspect if memory leak, this might not actually release the components?
		components.erase(entityID);


	}

	template<class T>
	void ComponentCollection<T>::hasEntity(int entityID){
		return components.contains(entityID);

	}




}