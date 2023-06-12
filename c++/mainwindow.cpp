#include "mainwindow.h"


MainWindow::MainWindow()
    :Application("cn.yatiger.cxx", Gio::APPLICATION_FLAGS_NONE)
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
    builder->get_widget("treeview_menu", menu);

    menu->set_model(menu_model.getModel());
    menu->expand_all();

    window->set_default_size(1200, 800);
    add_window(*window);
    window->show_all();
}


