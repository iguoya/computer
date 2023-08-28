#include "keyword.h"

KeyWord::KeyWord()
{

}

void KeyWord::run()
{
    display("你好 中文!!!");
    vector<string> msgs = {
        "hello",
        "world",
        "china"
    };
    displays(msgs);


    vector<string> columns = {
        "AA", "BB", "CC", "DD"
    };
    vector<vector<string> > result = {
        {"100", "ak", "123", "world"},
        {"111", "akm", "453", "woreeld"},
        {"123", "ak74", "789", "中文"},
        {"100", "ak", "123", "world"},
        {"111", "akm", "453", "woreeld"},
        {"123", "ak74", "789", "中文"},
        {"100", "ak", "123", "world"},
        {"111", "akm", "453", "woreeld"},
        {"123", "ak74", "789", "中文"},
        {"100", "ak", "123", "world"},
        {"111", "akm", "453", "woreeld"},
        {"123", "ak74", "789", "中文"},
    };
    displayTable(columns, result);
}

