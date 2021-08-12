// this file is purely for safekeeping

	/*
	struct ComponentCounter
	{
		static inline int componentCounter;
	};

	

	// guess we need this after all
	template <typename ComponentType>

	class Component
	{
	private:

		static inline int componentID()
		{
			static int componentID = ComponentCounter::componentCounter++;
			return componentID;
		}
	
	};

	
	// Helper utlity function because we can't just use the template's thing to call compID();

	template <typename C>
	static int GetComponentID() {
	  return Component<typename std::remove_const<C>::type>::componentID();
	}
	  // may want equiv to this?
	*/

	// ^ fuck all that shit, going to stop using ComponentIDs in order to depend on std::type_info