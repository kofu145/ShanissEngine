#pragma once
#include <unordered_map>


namespace ShanissCore
{

	// this const doesn't actually matter until (if doing) bitset is used.
	const std::size_t MAX_COMPONENTS = 64;


	class IComponentCollection
	{
	public:
		virtual ~IComponentCollection() = default;
	}; 

	template<class ComponentType>
	class ComponentCollection : public IComponentCollection
	{

	public:

		void insertData(int entityID, ComponentType component);

		void removeData(int entityID);

		void hasEntity(int entityID);

	private:
		// Not sure about utilizing the bitset, will look more into it later - 
		// check if component is null or not in the array for each EID for now

		//using ComponentBitset = std::bitset<MAX_COMPONENTS>;
		//using ComponentArray = std::array<ComponentType, ShanissCore::MAX_COMPONENTS>;
		// ComponentBitset componentBitset;
		using ComponentMap = std::unordered_map<std::size_t, ComponentType>;
		ComponentMap components;
		

	};
	
} 