#ifndef SYSTEM_H
#define SYSTEM_H
#include "component\ComponentManager.h"
namespace Walden{
    class SystemManager;

    // TODO assess the need for non entity-based systems (merge with subclass entitysystem)...
    class System {
    public:
        System(ComponentManager &componentManager) : componentManager(&componentManager) {}
        void setSystemManager(SystemManager *systemManager) { this->systemManager = systemManager; }

        virtual void update() = 0;
    protected:
        ComponentManager *componentManager;
        SystemManager * systemManager;
    };
}
#endif
