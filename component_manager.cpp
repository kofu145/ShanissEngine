#include "component_manager.h"

namespace ShanissCore {

    template<typename ComponentType>
    ComponentCollection<ComponentType> ComponentManager::getComponentArray()
    {
        // do the fuckin shit where u make the thing (inst new compcolle if non existant)

        return static_cast<ComponentCollection<ComponentType>*>(componentCollections[typeid(ComponentType)]);
    }

}