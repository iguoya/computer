#ifndef AUTO_H
#define AUTO_H

#include <product.h>
#include <iostream>

class Auto : public Product {
public:
    explicit Auto();
    void run() override;
};

#endif // AUTO_H
