#include "EntitySystem.h"

namespace Walden {
    void EntitySystem::update()  {
        beforeProcess();
        for (std::set<Entity *>::const_iterator iter = entities.begin(); iter != entities.end(); ++iter) {
            process(*iter);
        }
        afterProcess();
    }

    // Default entity systems care about all entities.
    void EntitySystem::addEntity(Entity& e) {
        entities.insert(&e);
    }
}
