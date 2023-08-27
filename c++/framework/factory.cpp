#include "factory.h"

Factory::Factory()
{

}

Product *Factory::create(Identifier type)
{
    switch(type) {
    case Identifier::Keyword:
        return new KeyWord;
    case Identifier::Auto:
        return new Auto;
    case Identifier::Const:
        break;
    default:
        return new KeyWord;
    }
}

