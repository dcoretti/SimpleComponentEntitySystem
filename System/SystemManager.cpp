#include "SystemManager.h"

#include "EntitySystem.h"
#include "entity/Entity.h"

#include <iostream>
namespace Walden {
    // Warning, allows duplicates.  I guess I could put a check in here..
    // Not using a set to avoid needing a second vector of systems or a const_cast
    void SystemManager::registerEntitySystem(EntitySystem & s) {
        entitySystems.push_back(&s);
        registerSystem(s);
    }

    void SystemManager::registerSystem(System &s) {
        allSystems.push_back(&s);
        s.setSystemManager(this);
    }


    // Add an entity to any sytstem that cares about the components attached to that entity
    // Must be done after component registration.
    void SystemManager::registerEntity(Entity &e) {
        vector<EntitySystem*>::iterator it;
        for (it = entitySystems.begin(); it != entitySystems.end(); ++it) {
            (*it)->addEntity(e);
        }
    }

    void SystemManager::updateSystems() {
        vector<System*>::iterator it;
        for (it = allSystems.begin(); it != allSystems.end(); ++it) {
            (*it)->update();
        }
    }
}