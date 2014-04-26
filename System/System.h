#ifndef SYSTEM_H
#define SYSTEM_H

#include "component\ComponentManager.h"
namespace Walden{
    // TODO assess the need for non entity-based systems...
    class System {
    public:
        System(ComponentManager * componentManager) : componentManager(componentManager) {}
        virtual void update() = 0;
    protected:
        ComponentManager * componentManager;
    };
}
#endif
