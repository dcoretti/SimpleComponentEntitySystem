#ifndef ENTITY_SYSTEM_H
#define ENTITY_SYSTEM_H

#include "System.h"
#include "entity/Entity.h"
#include "component/ComponentManager.h"
#include <set>

namespace Walden {
    /* Entity Systems are systems of logic that are performed on entities which meet a set of requirements
       for being considered within a system.
       ex: a movement system handles updating entities with both position and velocity components

       Entities are added to a system after creation/association with components.

       On each cycle of the engine an entity system will run update() which will run process on each entity that matched via
       addEntity.
    */
    class EntitySystem: public System {
    public:
        EntitySystem(ComponentManager* componentMgr) : System(componentMgr) {}
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
