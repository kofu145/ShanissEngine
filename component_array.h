#pragma once
#include <unordered_map>


namespace Shaniss::Core
{

	class IComponentArray
	{
	public:
		virtual ~IComponentArray() = default;
	}; 

	template<class ComponentType>
	class ComponentArray : public IComponentArray
	{

	public:

		void insertData(int entityID, ComponentType component);

		void removeData(int entityID);

	private:
		// Not sure about utilizing the bitset, will look more into it later - 
		// check if component is null or not in the array for each EID for now

		//using ComponentBitset = std::bitset<ShanissCore::MAX_COMPONENTS>;
		//using ComponentArray = std::array<ComponentType, ShanissCore::MAX_COMPONENTS>;
		// ComponentBitset componentBitset;
		using ComponentMap = std::unordered_map<std::size_t, ComponentType>;
		
		ComponentMap components;
		
	};
	
} 