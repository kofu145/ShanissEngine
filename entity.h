#pragma once
#include <cstdint>
#include "component.h"
#include <array>

namespace Shaniss::Core
{
    const unsigned int MAX_ENTITIES = 5000;

    const std::size_t MAX_COMPONENTS = 64;
    using ComponentArray = std::array<Component*, MAX_COMPONENTS>;

    // template<typename T>
    class Entity
    {
    public:
        
        const int id;

        // make sure assigning ids in constructor takes account of freed up entity ids
        Entity(int id);

        template<class T>
        bool hasComponent() const;

        template<class T>
        T& getComponent() const;

        template<class T>
        T& addComponent();

        template<class T>
        void removeComponent();

        // this needs to allow for what is said to describe constructor above (track free'd eIDs)
        void destroy();



    };
}

