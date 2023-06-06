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

using namespace Glib;
using namespace Gtk;

class MainWindow : public Application
{
public:
    MainWindow();

    //    virtual ~MainWindow() = default;

protected:
    void on_startup() override;
    void on_activate() override;

private:
    RefPtr<Builder> builder;
    ApplicationWindow *window;
    TreeView* treeview_menu;
    RefPtr<TreeStore> treemodel_menu;
    RefPtr<ListStore> list_store;

    class ModelColumns : public TreeModel::ColumnRecord
    {
    public:
        ModelColumns() { add(name); add(age); }

        TreeModelColumn<ustring> name;
        TreeModelColumn<ustring> age;
        TreeModelColumn<uint8_t> asge;
    };
};


//class MainWindow  : public Window
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
//    RefPtr<Builder> ui;
//    Window* window;
//};



#endif // MAINWINDOW_H
