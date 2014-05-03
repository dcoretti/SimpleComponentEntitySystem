#ifndef ENTITY_H
#define ENTITY_H
#include <bitset>
namespace Walden {
    /*
        container for a list of components.  
    */
    class Entity {
    public:
        Entity(int id);
        
        const int id; 

        bool hasComponent(unsigned int id);
        void setComponent(unsigned int id);
        void removeComponent(unsigned int id);

        // Leaving this const here as the component bound checks will only happen here anyway
        static const unsigned int maxBitIds = 64;  // maximum number of components per entity
    protected:
        std::bitset<maxBitIds> components;
    };
}

#endif
