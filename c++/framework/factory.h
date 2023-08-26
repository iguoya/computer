#ifndef FACTORY_H
#define FACTORY_H

#include "product.h"
#include "auto.h"

class Factory
{
public:
    Factory();
    static Product* create(string name);
};

#endif // FACTORY_H
