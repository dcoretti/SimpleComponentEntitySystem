#ifndef ENTITY_H
#define ENTITY_H

#include "../component/ComponentBitSet.h"
namespace Walden {
	class ComponentBitSet;
    /*
        container for a list of components.  
    */
    class Entity {
    public:
        Entity(int id);
        
        const int id;
        ComponentBitSet components;
    };
}
#endif
