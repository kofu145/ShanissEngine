#pragma once
#include <type_traits>


namespace ShanissCore {

	// purely exists to serve as a base class, every component MUST inherit this.
	class Component
	{
		// just in case, for now
		static int componentID;

	};
}
