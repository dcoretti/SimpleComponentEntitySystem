#ifndef COMPONENT_H
#define COMPONENT_H

#include "entity/Entity.h"
#include <functional>
#include <string>
//#include <boost/functional/hash.hpp>

namespace Walden
{

//class Entity;

class Component 
{
public:
    // Each component needs to define a global name.  This is to avoid
    // using rtti for whatever speedup that actually might get
    // used in component manager as a memory location-based "hashcode" of the component name
    //virtual const std::string getComponentName() const = 0;
    // Make this a static so we can preassign the bitId and make that a constant
    /*std::size_t getUid() const {
        std::hash<std::string> hash_fn;
        // return boost::hash<std::string>()(getComponentName());} // intptr_t? 
        return hash_fn(getComponentName());
    }*/

    ///////////////////////////////////////////////////////
    // Methods overridden by subclasses of components

    virtual void onCreate() {}
    virtual void onAttachToEntity(Entity &e) {}
    virtual void onRemoveFromEntity() {}

    // Called each update cycle
    virtual void onUpdate(unsigned long deltaTime) = 0;



    //void setUid(size_t uid) { this->uid = uid; }
    //size_t getUid() { return uid; }
protected:
    //size_t uid;     // Cached from component manager to avoid rtti too often

    // The bit id is assigned at creation based on the componentUid.  This way we can give a unique number for bitsets 
    // based on the hash that will be consistent.
    //unsigned int bitId;
};

}
#endif
