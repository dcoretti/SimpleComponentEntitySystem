#ifndef COMPONENT_H
#define COMPONENT_H

#include "entity/Entity.h"

namespace Walden
{
    class Component 
    {
    public:
        // Each component needs to define a global name.  This is to avoid
        // using rtti for whatever speedup that actually might get
        // used in component manager as a memory location-based "hashcode" of the component name
        //virtual const std::string getComponentName() const = 0;
        // Make this a static so we can preassign the bitId and make that a constant

        ///////////////////////////////////////////////////////
        // Methods overridden by subclasses of components
        virtual void onCreate() {}
        virtual void onAttachToEntity(Entity &e) {}
        virtual void onRemoveFromEntity() {}

        // Called each update cycle
        virtual void onUpdate(unsigned long deltaTime) = 0;
    };

}
#endif
