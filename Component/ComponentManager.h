#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H
#include <map>
#include "Component.h"
#include "Entity/Entity.h"
namespace Walden
{
    /* ComponentManager handles associations between sets of entities and components. 
       Handles book keeping of entities which have a certain component type.
    */
    class ComponentManager {
    public:
        ComponentManager();
        ~ComponentManager();

        void addComponent(Entity& entity, Component & component);
        void removeComponent(Entity& entity, Component& component);
        Component * getComponentFromEntityByType(const Entity& e, size_t componentUid) const;

        unsigned int getComponentBitId(size_t componentUid) const;
        unsigned int getComponentBitId(Component& component) const;
        template<class T> unsigned int getComponentBitId() const { return getComponentBitId(getComponentUidFromType<T>()); }
       
        // TODO get entities that have a particular component type?
        // TODO get component, entity pairs by type?

        template<class T> size_t getComponentUidFromType() const { return std::hash<std::string>()(typeid(T).name()); }
        std::string getComponentName(const Component &c) const;
        size_t getComponentUid(const Component &c) const;

    private:
        void initializeComponent(Component& component) const; // called when a new entity is attached
        unsigned int assignBitIdToNewComponents(Component& c);

        // Mapping of component type id to a map of entities  (component type id -> (entity id -> component)
        std::map<size_t, std::map<int, Component *> > entitiesByComponentUid;

        // Mapping of uid -> assigned bit id for faster lookup of components by entity
        std::map<size_t, unsigned int> componentTypeBitIds;
        unsigned int currentBitId;
    };
}
#endif
