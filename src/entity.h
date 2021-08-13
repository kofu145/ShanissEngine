#pragma once
#include <cstdint>
#include "component_manager.h"
#include "component.h"
#include <array>

namespace ShanissCore
{
    const unsigned int MAX_ENTITIES = 5000;

    /*
    Entity

        Every entity holds an id, which is used to reference its components under ComponentCollection,
        which are all managed by ComponentManager.

        All entities hold a pointer that refers to the ComponentManager (singleton), and its own hascomp,
        getcomp, addcomp, etc all utilize it to manage components.

        Upon destruction, the entity id is flagged for reusage (the constructor will call a helper method
        to recycle entity IDs)

        Usage:
            Entity entity();

            entity.hasComponent<Transform>();

            entity.getComponent<Transform>().position = 10;

            entity.addComponent<Transform>();

        As all of the methods are handled by Entity itself, there is no need for an EntityManager,
        and therefore it does not exist. (May change? Suggestion: have entityManager over singular static
        method to handle EIDs)

    */


    // template<typename T>
    class Entity
    {
    public:
        
        const int id;
        

        // make sure assigning ids in constructor takes account of freed up entity ids
        Entity();

        template<class T>
        bool hasComponent() const;

        template<class T>
        T& getComponent() const;

        template<class T>
        T& addComponent(T component);

        template<class T>
        void removeComponent();

        // this needs to allow for what is said to describe constructor above (track free'd eIDs)
        void destroy();
    
    private:


    };
}

