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

