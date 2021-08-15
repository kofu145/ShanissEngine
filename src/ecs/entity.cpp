#include "entity.h"
#include <cstdint>


namespace ShanissCore {

	// write static helper function for recycling id behavior, like ``: id(func(id))``
	Entity::Entity(): id(id) { 
		
	}

	template<class T>
	bool Entity::hasComponent() const {
		// Checks if specified entity's id exists within the component array for directed component
		return ComponentManager::getInstance()->getComponentArray<T>().hasEntity(this->id);

	}

	template<class T>
	T& Entity::getComponent() const
	{
		// Retrieves specified data from the component array for specified component, for entity

		// grab component array for that type, call get data on it
		return ComponentManager::getInstance()->getComponentArray<T>().getData(this->id);

	}

	template<class T>
	T& Entity::addComponent(T component)
	{
		// Inserts specified data into the component array for specified component, for entity
		// (getcomponentarray should be assigning all the arrays, checking every time)

		return ComponentManager::getInstance()->getComponentArray<T>().insertData(component);

	}

	template<class T>
	void Entity::removeComponent()
	{
		// get componentarray from component manager, then removedata()
		return ComponentManager::getInstance()->getComponentArray<T>().removeData(this->id);

	}

}
