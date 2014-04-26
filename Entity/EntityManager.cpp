#include "EntityManager.h"

namespace Walden {
    EntityManager::EntityManager(): currentEntityId(0) {
    }

    EntityManager::~EntityManager() {
        std::map<int, Entity *>::iterator it;
        for (it = entitiesById.begin(); it != entitiesById.end(); ++it) {
            delete it->second;
        }
    }

    Entity * EntityManager::createEntity() {
       Entity *e = new Entity(currentEntityId);
        entitiesById[currentEntityId] = e;
        currentEntityId++;
        return e;
    }
}