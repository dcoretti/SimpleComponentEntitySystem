#include "SystemManager.h"
#include <iostream>
namespace Walden {
    void SystemManager::registerSystem(EntitySystem * s) {
        systems.insert(s);
    }

    // Add an entity to any sytstem that cares about the components attached to that entity
    // Must be done after component registration.
    void SystemManager::registerEntity(Entity &e) {
        set<EntitySystem *>::iterator it;
        for (it = systems.begin(); it != systems.end(); ++it) {
            (*it)->addEntity(e);
        }
    }

    void SystemManager::updateSystems() {
        set<EntitySystem *>::iterator iter;
        for (iter = systems.begin(); iter != systems.end(); ++iter) {
            (*iter)->update();
        }
    }

}