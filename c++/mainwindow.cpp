#include "mainwindow.h"


MainWindow::MainWindow()
    :Application("cn.yatiger.c++", Gio::APPLICATION_FLAGS_NONE)
{
    set_application_name("c++ 专项练习");
}

void MainWindow::on_startup()
{
    Application::on_startup();
    builder = Builder::create();
    try {
        builder->add_from_file("resources/window.glade");
    } catch (const Glib::Error &ex) {
        MessageDialog dialog("Error building UI: " + ex.what());
        dialog.run();
    }
}

void MainWindow::on_activate()
{
    builder->get_widget("window", window);
    builder->get_widget("treeview_menu", treeview_menu);

    ModelColumns columns;

    list_store = ListStore::create(columns);

//        auto items = Glib::RefPtr<TreeStore>::cast_dynamic(
//            builder->get_object("treemodel_menu")
//        );
    treeview_menu->set_model(list_store);

    TreeModel::Row row = *(list_store->append());
    row[columns.chapter] = "John";
    row[columns.identifier] = "中文描述";
    row[columns.priority] = 30;

    row = *(list_store->append());
    row[columns.chapter] = "Lisa";
    row[columns.identifier] = "中文描述";
    row[columns.priority] = 27;
    //    builder->get_widget("treestore_menu", treemodel_menu);
    //    auto items = Glib::RefPtr<TreeStore>::cast_dynamic(
    //        builder->get_object("treemodel_menu")
    //    );

    //    assert(items);


//    TreeModel::Row row = *(items->append());

    window->set_default_size(1200, 800);
    add_window(*window);
    window->show_all();
}

//MainWindow::MainWindow(BaseObjectType *parent)
//    : Window(parent),
//      ui(Builder::create_from_file("/home/tiger/computer/c++/window.glade"))
//{
//    ui->get_widget("window", window);
//    window->show();
//}

//MainWindow::MainWindow(BaseObjectType *parent, const Glib::RefPtr<Builder> &glade)
//    : Window(parent), builder(glade)
//{
//    builder->get_widget("window", window);
//    window->show();
//}

