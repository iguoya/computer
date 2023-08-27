#ifndef FACTORY_H
#define FACTORY_H

#include "identifier.h"
#include "product.h"

#include "keyword.h"
#include "auto.h"

class Factory
{
public:
    Factory();
    static Product* create(Identifier type);
};

#endif // FACTORY_H
