#ifndef KEYWORD_H
#define KEYWORD_H
#include "product.h"

typedef struct {
    size_t id;
    string name;
    string input;
    string result;
} Row;

class KeyWord : public Product
{
public:
    KeyWord();
    void run() override;
//    vector<Row> result;
};

#endif // KEYWORD_H
