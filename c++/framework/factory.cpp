#include "factory.h"

Factory::Factory()
{

}

Chapter *Factory::create(string name)
{
    if(name == "auto") {
        return new Auto;
    }
    return new Auto;
}
