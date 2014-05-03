#include "Entity.h"

namespace Walden {
    Entity::Entity(int id): id(id) {
    }

    void Entity::setComponent(unsigned int id) {
        components.set(id);
    }

    void Entity::removeComponent(unsigned int id) {
        components.set(id, false);
    }

    bool Entity::hasComponent(unsigned int id) {
        return components[id]; 
    }
}