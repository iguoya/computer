#include "factory.h"

Factory::Factory()
{

}

Product *Factory::create(string name)
{
    if(name == "auto") {
        return new Auto;
    }
    return new Auto;
}
