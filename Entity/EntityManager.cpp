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

    // TODO keep track of freed entity ids and reuse those first.
    Entity * EntityManager::removeEntity(int id) {
        std::map<int, Entity *>::iterator it = entitiesById.find(id);
        if (it != entitiesById.end()) {
            Entity * e = it->second;
            entitiesById.erase(it);
            return e;
        }
        else {
            throw std::exception("Entity with id not found!");
        }
    }
}