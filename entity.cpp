#include "entity.h"
#include <cstdint>


namespace Shaniss::Core {

	Entity::Entity(int id): id(id) { // write helper function for recycling id behavior, like ``: id(func(id))``
	}

	template<class T>
	bool Entity::hasComponent() const {
		return
		// get component array equivalent of unordered_map::contains()?
	}

	template<class T>
	T& Entity::getComponent() const
	{
		// grab component array for that type, call get data on it
	}

	template<class T>
	T& Entity::addComponent()
	{
		// getcomponentarray<T> from component manager, then play insert data on that array
		// (getcomponentarray should be assigning all the arrays, checking every time)
	}

	template<class T>
	void Entity::removeComponent()
	{
		// get componentarray from component manager, then removedata()
	}

}
