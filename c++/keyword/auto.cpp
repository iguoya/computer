#include "auto.h"
//#include <format>

template <typename T>
string get(){
    auto value = T::get();
//    cout << val << endl;
//    char str[64] = {0};
//    snprintf(str, sizeof(str)-1, "%s", val);
//    return string(str);
    return (boost::format("%d") % value).str();
}


Auto::Auto() {}

void Auto::run() {
    display((boost::format("类型A : get 返回 %d") %  get<AutoA>()).str());
    display((boost::format("类型B : get 返回 %d") %  get<AutoB>()).str());
//    display(get<AutoB>());
}

const char *AutoB::get()
{
    return "http://c.biancheng.net/cplus/";
}

int AutoA::get()
{
    return 100;
}
