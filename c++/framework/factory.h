#ifndef FACTORY_H
#define FACTORY_H

#include "chapter.h"
#include "auto.h"

class Factory
{
public:
    Factory();
    static Chapter* create(string name);
};

#endif // FACTORY_H
