#ifndef CHAPTER_H
#define CHAPTER_H
#include <gtkmm.h>
#include <sigc++/sigc++.h>

using namespace std;
using namespace Glib;
class Product {
public:
    Product();
    virtual ~Product();
    virtual void run() = 0;

    sigc::signal<void(const string &)> display;
    sigc::signal<void(const vector<string> &)> displays;

    sigc::signal<void(vector<string> columns, vector<vector<string> > result)> displayTable;

    //  sigc::signal<void(const vector<string> &)> set_columns;
    //  sigc::signal<void(const vector<vector<string>> &)> display_table;
};

#endif // CHAPTER_H
