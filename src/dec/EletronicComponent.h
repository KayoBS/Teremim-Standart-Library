#ifndef TEREMIM_ELETRONIC_COMPONENT_H_INCLUDED
#define TEREMIM_ELETRONIC_COMPONENT_H_INCLUDED

#include <Arduino.h>

class EletronicComponent
{
public:
    //O nome também poderia ser begin()
    virtual void start() = 0;
};

#endif
