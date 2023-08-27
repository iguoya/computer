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

class MainWindow : public Gtk::ApplicationWindow
{
public:
    MainWindow(GtkApplicationWindow* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
    static MainWindow* create();
protected:
    void on_selected();
    void display(string msg);
private:
    RefPtr<Gtk::Builder> builder;
    static MainWindow* window;

    Gtk::TreeView* menu;
    MenuModel menuModel;
    ModelColumns column;

    Gtk::TreeView* listView;
    RefPtr<Gtk::ListStore> listStore;
    Gtk::TreeView* treeView;
    RefPtr<Gtk::TreeStore> treeStore;

    Gtk::TextView* textView;
    Glib::RefPtr<Gtk::TextBuffer> textBuffer;
    RefPtr<Gtk::TextBuffer::Mark> m_endMark;


    class TModelColumns : public Gtk::TreeModel::ColumnRecord
    {
    public:
        TModelColumns() { add(name); add(age); }

        Gtk::TreeModelColumn<Glib::ustring> name;
        Gtk::TreeModelColumn<Glib::ustring> age;
    };

};


#endif // MAINWINDOW_H
