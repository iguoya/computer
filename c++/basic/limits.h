#ifndef LIMITS_H
#define LIMITS_H

#include "product.h"
class Limits : public Product
{
public:
    Limits();
    void run() override;
};
REGISTERCLASS(Limits);
#endif // LIMITS_H
