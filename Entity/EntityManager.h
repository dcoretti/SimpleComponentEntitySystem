#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <map>
#include "Entity.h"

namespace Walden
{
    class Entity;
    /* Acts as a registrar for entities.  Handles creation and destruction of entities */
    class EntityManager {
    public:
        EntityManager();
        ~EntityManager();
        Entity * createEntity();
    private:
        std::map<int, Entity *> entitiesById;
        int currentEntityId;
    };
}
#endif
