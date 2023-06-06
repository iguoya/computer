#include "mainwindow.h"

//MainWindow::MainWindow()
//    : Gtk::Application("org.wlfgang.silverclaw", Gio::APPLICATION_FLAGS_NONE),
//    window(nullptr)
//{
//    Glib::set_application_name("c++ 专项练习");
//}

MainWindow::MainWindow() : Gtk::Application(
                               "org.wlfgang.silverclaw",
                               Gio::APPLICATION_FLAGS_NONE),
    window{nullptr} {
    Glib::set_application_name("silverclaw");
}

void MainWindow::on_startup()
{
    Application::on_startup();
    builder = Gtk::Builder::create();
    try {
        builder->add_from_file("resources/window.glade");
    } catch (const Glib::Error &ex) {
        Gtk::MessageDialog dialog("Error building UI: " + ex.what());
        dialog.run();
    }

}

void MainWindow::on_activate()
{
    builder->get_widget("window", window);
    builder->get_widget("treeview_menu", treeview_menu);

    ModelColumns columns;

    list_store = Gtk::ListStore::create(columns);

//        auto items = Glib::RefPtr<Gtk::TreeStore>::cast_dynamic(
//            builder->get_object("treemodel_menu")
//        );
    treeview_menu->set_model(list_store);

    Gtk::TreeModel::Row row = *(list_store->append());
    row[columns.name] = "John";
    row[columns.age] = "30";

    row = *(list_store->append());
    row[columns.name] = "Lisa";
    row[columns.age] = "27";
    //    builder->get_widget("treestore_menu", treemodel_menu);
    //    auto items = Glib::RefPtr<Gtk::TreeStore>::cast_dynamic(
    //        builder->get_object("treemodel_menu")
    //    );

    //    assert(items);


//    Gtk::TreeModel::Row row = *(items->append());

    window->set_default_size(1200, 800);
    add_window(*window);
    window->show_all();
}

//MainWindow::MainWindow(BaseObjectType *parent)
//    : Gtk::Window(parent),
//      ui(Gtk::Builder::create_from_file("/home/tiger/computer/c++/window.glade"))
//{
//    ui->get_widget("window", window);
//    window->show();
//}

//MainWindow::MainWindow(BaseObjectType *parent, const Glib::RefPtr<Gtk::Builder> &glade)
//    : Gtk::Window(parent), builder(glade)
//{
//    builder->get_widget("window", window);
//    window->show();
//}

