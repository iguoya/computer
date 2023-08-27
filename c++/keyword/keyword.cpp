#include "keyword.h"

KeyWord::KeyWord()
{

}

void KeyWord::run()
{
    display("你好 中文!!!");
//    result = {
//        {100, "ak", "123", "world"},
//        {111, "akm", "453", "woreeld"},
//        {123, "ak74", "789", "中文"},
//    };
    vector<string> result = {
        "hello",
        "world",
        "china"
    };
    displays(result);
}
