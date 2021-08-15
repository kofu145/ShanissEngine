#pragma once
#include <type_traits>


namespace ShanissCore {

	// Base class for all components. Every component MUST inherit this.
	class Component
	{
		// just in case, for now
		static int componentID;

	};
}
