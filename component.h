#pragma once


namespace Shaniss::Core {
	
	struct ComponentCounter
	{
		static inline int componentCounter;
	};

	class Component
	{

	private:

		static inline int componentID()
		{
			static int componentID = ComponentCounter::componentCounter++;
			return componentID;
		}
	
	};

	/*
	// Util method for getting family given type

	template <typename C>
	static int GetComponentID() {
	  return Component<typename std::remove_const<C>::type>::componentID();
	}
	  // mat want equiv to this?
	*/

}
