#include "component_manager.h"
#include <memory>

namespace ShanissCore {

    std::unique_ptr<ComponentManager> ShanissCore::ComponentManager::instance = nullptr;

    ComponentManager* ComponentManager::getInstance()
    {
        if (ComponentManager::instance == nullptr){
            ComponentManager::instance = std::unique_ptr<ComponentManager>(new ComponentManager());

        }
    
        return ComponentManager::instance.get();

    }

    void ComponentManager::clear(){
        componentCollections.clear();
    }

    template<typename ComponentType>
    ComponentCollection<ComponentType> ComponentManager::getComponentArray()
    {
        // do the fuckin shit where u make the thing (inst new compcolle if non existant)

        return static_cast<ComponentCollection<ComponentType>*>(componentCollections[typeid(ComponentType)]);
    

    
    }

}