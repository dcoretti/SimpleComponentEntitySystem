#ifndef COMPONENT_H
#define COMPONENT_H

namespace Walden
{

class Component 
{
public:
    virtual void onCreate() {}

    // Called each update cycle
    virtual void onUpdate(unsigned long deltaTime) = 0;
};

}
#endif