#include "mainapplication.h"



MainApplication::MainApplication()
    : Gtk::Application("dev.yatiger.c++")
{

}

Glib::RefPtr<MainApplication> MainApplication::create() {
    return Glib::RefPtr<MainApplication>(new MainApplication());
}

MainWindow* MainApplication::create_window() {
    auto window = MainWindow::create();

    add_window(*window);
    window->signal_hide().connect(sigc::bind(sigc::mem_fun(*this, &MainApplication::on_hide_window), window));

    return window;
}

void MainApplication::on_activate() {
    auto window = create_window();
    window->present();
}

void MainApplication::on_hide_window(Gtk::Window* window) {
    delete window;
}
