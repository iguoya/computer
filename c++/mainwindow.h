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
    MainWindow(GtkApplicationWindow* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

protected:
    void on_selected();

private:
    RefPtr<Gtk::Builder> builder;

    TreeView* menu;
    MenuModel menuModel;
    ModelColumns column;
    RefPtr<TreeStore> list_store;

    Gtk::TextView* textView;
    Glib::RefPtr<Gtk::TextBuffer> textBuffer;
};


#endif // MAINWINDOW_H
