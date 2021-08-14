#include "component_manager.h"
#include <memory>

namespace ShanissCore {

    // alias cause original type is too long
    ComponentManager::componentManagerPtr ShanissCore::ComponentManager::instance = nullptr;

    ComponentManager::ComponentManager(): 
    componentCollections(
        std::unordered_map<const char*, std::shared_ptr<IComponentCollection>>()
    )
    
    {

    }


    ComponentManager* ComponentManager::getInstance()
    {
        if (ComponentManager::instance == nullptr){
            ComponentManager::instance = ComponentManager::componentManagerPtr(new ComponentManager(), Deleter<ComponentManager>());

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
        const char* typeName = typeid(ComponentType).name();
        return static_cast<ComponentCollection<ComponentType>*>(componentCollections[typeName]);
    

    
    }

}