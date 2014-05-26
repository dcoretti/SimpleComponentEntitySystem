#ifndef SYSTEM_MGR_H
#define SYSTEM_MGR_H

#include <vector>
#include <iostream>
using std::vector;

namespace Walden {
    class EntitySystem;
    class System;
    class Entity; 

    class SystemManager {
    public:
        void registerEntitySystem(EntitySystem &s);
        void registerSystem(System &s);
        void registerEntity(Entity &e);

        virtual void updateSystems();
    protected:
        vector<EntitySystem *> entitySystems;
        vector<System *> allSystems;
    };
}
#endif