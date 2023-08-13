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
//using namespace Gtk;

class MainWindow : public Gtk::Window
{
public:
    MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
    static MainWindow* create();
protected:
    const Glib::RefPtr<Gtk::Builder> builder;


//public:
//    MainWindow();

//    //    virtual ~MainWindow() = default;

//protected:
//    void on_startup() override;
//    void on_activate() override;
//    void on_selected();

//private:
//    RefPtr<Gtk::Builder> builder;
//    ApplicationWindow* window;
//    TreeView* menu;
//    MenuModel menuModel;
//    ModelColumns column;

//    RefPtr<TreeStore> list_store;

//    Gtk::TextView* textView;
//    Glib::RefPtr<Gtk::TextBuffer> textBuffer;

    //    struct


};


//class MainWindow : public Gtk::Window {
//public:
//  MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
//  static MainWindow* create();
//protected:
//  const Glib::RefPtr<Gtk::Builder> builder;
//};




#endif // MAINWINDOW_H
