#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>
#include <gtkmm/application.h>
#include <gtkmm/applicationwindow.h>
#include <gtkmm/builder.h>
#include <giomm.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/filechooser.h>
#include <gtkmm/filechooserdialog.h>
#include "assert.h"

class MainWindow : public Gtk::Application
{
public:
    MainWindow();

    //    virtual ~MainWindow() = default;

protected:
    void on_startup() override;
    void on_activate() override;

private:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::ApplicationWindow *window;
    Gtk::TreeView* treeview_menu;
    Glib::RefPtr<Gtk::TreeStore> treemodel_menu;
    Glib::RefPtr<Gtk::ListStore> list_store;

    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
    public:
        ModelColumns() { add(name); add(age); }

        Gtk::TreeModelColumn<Glib::ustring> name;
        Gtk::TreeModelColumn<Glib::ustring> age;
    };
};


//class MainWindow  : public Gtk::Window
//{
//public:
//    MainWindow(BaseObjectType* parent = nullptr);

////    {
////        if(ui) {
////            ui->get_widget("window", window);
////            set_default_size(1000, 600);
////        }

//////        set_title("hello");
//////        show_all_children();
////        show_all();
////    };

//protected:
//    Glib::RefPtr<Gtk::Builder> ui;
//    Gtk::Window* window;
//};



#endif // MAINWINDOW_H
