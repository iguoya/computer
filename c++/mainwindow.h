#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>
#include <giomm.h>
#include "assert.h"
#include "menumodel.h"
#include <iostream>
#include "factory.h"

using namespace std;
using namespace Glib;
using namespace Gtk;

class MainWindow : public Gtk::ApplicationWindow
{
public:
    MainWindow();
//    MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
//    static MainWindow* create();


protected:



private:
    RefPtr<Gtk::Builder> builder;

};


#endif // MAINWINDOW_H
