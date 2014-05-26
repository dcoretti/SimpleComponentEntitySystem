#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H
#include <map>
#include "Component.h"
#include "entity/Entity.h"

namespace Walden
{
    /* ComponentManager 
     * Handles associations between sets of entities and components. 
     * Handles book keeping of entities which have a certain component type.
     *
     *  Components are stored with two identifiers:
     *  1. ComponentUid: the hash of the component's class name
     *  2. ComponentBitId: a unique bit in a bitset corresponding to this entity.  This allows entities to only have 
     *     a set of bits for the components they store and components themselves can be stored elsewhere.  The mapping
     *     of entity->actual component is also held here.
     *
     *  Components get uids/bit ids in one of two ways:
     *  1. Coponents are registered using registerComponentBitId BEFORE being added to an entity via addComponent
     *  2. Calling addComponent will register a new bit id / component id if they don't already exist.
     *  
     *  When registering an entity with an EntitySystem, the system will check if the entity is relevant by checking
     *  that the desired bits are set.  Therefore to avoid annoying order of operations of creating and registering entities
     *  and components, method 1 should be done FIRST with all components expected to be used.
    */

    // TODO get entities that have a particular component type?
    // TODO get component, entity pairs by type?
    class ComponentManager {
    public:
        ComponentManager();

        // Get the bit id for this type without associating with an entity
        template <class T> unsigned int registerComponentBitId() { return assignBitIdToComponentType(getComponentUidFromType<T>()); };
        void addComponent(Entity& entity, Component & component);
        void removeComponent(Entity& entity, Component& component);
        Component * getComponentFromEntityByType(const Entity& e, size_t componentUid) const;

        unsigned int getComponentBitId(size_t componentUid) const;
        unsigned int getComponentBitId(const Component& component) const;
        template<class T> unsigned int getComponentBitId() const { return getComponentBitId(getComponentUidFromType<T>()); }
        template<class T> size_t getComponentUidFromType() const { return std::hash<std::string>()(typeid(T).name()); }
        std::string getComponentName(const Component &c) const;
        size_t getComponentUid(const Component &c) const;

    private:
        void initializeComponent(Component& component) const; // called when a new entity is attached
        unsigned int assignBitIdToComponentType(size_t uid);
        unsigned int assignBitIdToNewComponents(const Component& c);

        // Mapping of component type id to a map of entities  (component type id -> (entity id -> component)
        std::map<size_t, std::map<int, Component *> > entitiesByComponentUid;
        // Mapping of uid -> assigned bit id for faster lookup of components by entity
        std::map<size_t, unsigned int> componentUidBitIds;

        unsigned int currentBitId;
    };
}
#endif
