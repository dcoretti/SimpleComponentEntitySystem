#include "ComponentManager.h"
#include <typeinfo>

namespace Walden
{
    ComponentManager::ComponentManager(): currentBitId(0) {
    }

    ComponentManager::~ComponentManager() {
    }

    void ComponentManager::addComponent(Entity& entity, Component& component) {
        unsigned int bitId = assignBitIdToNewComponents(component);
        const size_t componentUid = getComponentUid(component);

        std::map<size_t, std::map<int, Component *> >::iterator iter(entitiesByComponentUid.find(componentUid));

        if (iter == entitiesByComponentUid.end()) {
            // Initialize a new component
            // no entities have this component yet
            std::map<int, Component *> entityComponents;
            entityComponents[entity.id] = &component;
            entitiesByComponentUid[componentUid] = entityComponents;
        }
        else {
            // otherwise add the entry to the existing entity's components
            iter->second[entity.id] = &component;
        }
        entity.components.addComponent(bitId);
    }

    void ComponentManager::removeComponent(Entity& entity, Component& component) {
        std::map<size_t, std::map<int, Component *> >::iterator iter(entitiesByComponentUid.find(getComponentUid(component)));
        if (iter != entitiesByComponentUid.end()) {
            std::map<int, Component *>::iterator iter2(iter->second.find(entity.id));
            if (iter2 != iter->second.end()) {
                iter->second.erase(iter2);
            }
        }
        entity.components.removeComponent(componentTypeBitIds.find(getComponentUid(component))->second);
    }

    Component * ComponentManager::getComponentFromEntityByType(const Entity& e, size_t componentUid) const {
        std::map<size_t, std::map<int, Component *> >::const_iterator componentEntities;
        componentEntities = entitiesByComponentUid.find(componentUid);
        if (componentEntities == entitiesByComponentUid.end())
        {
            throw std::exception("No components of this type registered.");
        }
        
        std::map<int, Component *>::const_iterator componentForEntity = componentEntities->second.find(e.id);
        if (componentForEntity == componentEntities->second.end())
        {
            throw std::exception((std::string("Entity of id: ") + std::to_string(e.id) + std::string(" has no component with Uid: ") + std::to_string(componentUid)).c_str());
        }

        return componentForEntity->second;
    }

    unsigned int ComponentManager::getComponentBitId(Component& component) const {
        return getComponentBitId(getComponentUid(component));
    }

    unsigned int ComponentManager::getComponentBitId(size_t componentUid) const {
        std::map<size_t, unsigned int>::const_iterator findIter = componentTypeBitIds.find(componentUid);
        if (findIter == componentTypeBitIds.end()) {
            throw std::exception("component doesn't exist!");
        }
        return findIter->second;
    }

    // Assign a new global bit id for each unique component type (based on uid)
    unsigned int ComponentManager::assignBitIdToNewComponents(Component& component) {
        size_t uid = getComponentUid(component);
        std::map<size_t, unsigned int>::iterator findIter = componentTypeBitIds.find(uid);
        if (findIter == componentTypeBitIds.end()) {
            if (currentBitId > sizeof(unsigned long long int)) {
                throw std::exception("The number of registered components is too high!");
            }
            componentTypeBitIds[uid] = currentBitId;
            return currentBitId++;
        }

        return findIter->second;
    }

    std::string ComponentManager::getComponentName(const Component& c) const {
        return typeid(c).name();
    }

    size_t ComponentManager::getComponentUid(const Component& c) const {
        return std::hash<std::string>()(getComponentName(c));
    }
}
