#ifndef AUTO_H
#define AUTO_H

#include <product.h>


class AutoA{
public:
    static int get();
};
class AutoB{
public:
    static const char* get();
};



class Auto : public Product {
public:
    explicit Auto();
    void run() override;
};
REGISTERCLASS(Auto);
#endif // AUTO_H
