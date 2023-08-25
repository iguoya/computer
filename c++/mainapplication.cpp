#include "mainapplication.h"

MainWindow* MainApplication::window;

MainApplication::MainApplication()
    : Gtk::Application("cn.yatiger.cpp", Gio::APPLICATION_FLAGS_NONE)
{
    set_application_name("c++ 专项练习");
}



Glib::RefPtr<MainApplication> MainApplication::create() {
    return Glib::RefPtr<MainApplication>(new MainApplication());
}

void MainApplication::on_activate() {
    window = create_window();
    window->present();
}


MainWindow* MainApplication::create_window() {
//    auto window = MainWindow::create();

    window = new MainWindow;

    add_window(*window);


    window->signal_hide().connect(sigc::bind(sigc::mem_fun(*this, &MainApplication::on_hide_window), window));

    return window;
}





void MainApplication::on_hide_window(Gtk::Window* window) {
    delete window;
}
