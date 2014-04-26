#ifndef SYSTEM_MGR_H
#define SYSTEM_MGR_H

#include "EntitySystem.h"
#include <set>

using std::set;

namespace Walden {
    class SystemManager {
    public:
        void registerSystem(EntitySystem * s);
        void registerEntity(Entity &e);

        void updateSystems();
    private:
        set<EntitySystem *> systems;
    };
}
#endif