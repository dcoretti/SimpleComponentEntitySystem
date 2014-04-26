#ifndef COMPONENT_BIT_SET_H
#define COMPONENT_BIT_SET_H

namespace Walden {
    /* 
        Simple bit set for determining which combination of components an entity has. 
        Limited to 64 entities at this point.. 
        TODO: extend entity capabilities with some fancier bit twiddling 
    */
    class ComponentBitSet {
    public:
        ComponentBitSet(): bitSet(0) {}
        void addComponent(unsigned int componentBitId);
        void removeComponent(unsigned int componentBitId);
        bool hasComponent(unsigned int componentBitId);
    private:
        unsigned long long int bitSet;
    };
}

#endif