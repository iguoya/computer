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


    //    void MainWindow::displayTable(, )
    //    {

    Gtk::TreeModelColumn<ustring> a;
    Gtk::TreeModelColumn<ustring> b;
    Gtk::TreeModelColumn<ustring> c;
    Gtk::TreeModelColumn<ustring> d;
    //    vector<Gtk::TreeModelColumn<ustring>> models(4);

    pair<string, Gtk::TreeModelColumn<ustring> > ss("id", a);
    vector<pair<string, Gtk::TreeModelColumn<ustring> > > columns = {
        {"id", a},
        {"name", b},
        {"num", c},
        {"content", d}
    };
    //    vector<pair<string, string>> sv {
    //        {"a", "b"},
    //    };
//    KeyWord::ModelColumns model;
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

