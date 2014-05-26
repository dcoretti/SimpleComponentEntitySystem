#ifndef ENTITY_SYSTEM_H
#define ENTITY_SYSTEM_H

#include "SystemManager.h"
#include "System.h"
#include "entity/Entity.h"
#include "component/ComponentManager.h"
#include <set>

namespace Walden {
    /* Entity System
     *  An entity system is a system of logic concerning entities with particular components attached.
     *        ex: a movement system handles updating entities with both position and velocity components
     *
     *  When entities are added to the system, the subclass must define which entity types it cares about to 
     *  filter entities to be processed.  Default behavior is to care about and track all entities.
     *  
     *  The component manager is used to identify components and the bit they represent on the entity bit set
     *  in order to identify if an entity has the desired combination of components.
     *  Entities are added to a system after creation/association with components.
    */
    class EntitySystem: public System {
    public:
        EntitySystem(ComponentManager& componentMgr) : System(componentMgr) {}
        virtual void update();
        virtual void addEntity(Entity& e); // only add a entity if relevant 
    protected:
        virtual void beforeProcess() {};
        virtual void afterProcess() {};
    
        virtual void process(Entity * e) = 0;  // do work on an individual entity

        std::set<Entity *> entities; // relevant entities
    };
}
#endif
