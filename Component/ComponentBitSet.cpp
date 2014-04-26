#include "ComponentBitSet.h"

namespace Walden {
    void ComponentBitSet::addComponent(unsigned int componentBitId) {
        bitSet |= (unsigned long long) 1 << componentBitId;
    }

    void ComponentBitSet::removeComponent(unsigned int componentBitId) {
        bitSet ^= (unsigned long long) 1 << componentBitId;
    }

    bool ComponentBitSet::hasComponent(unsigned int componentBitId) {
        return (bitSet & (unsigned long long)1 << componentBitId) > 0;
    }
}