#include "mainapplication.h"

MainWindow *MainApplication::window;

MainApplication::MainApplication()
    : Gtk::Application("cn.yatiger.cpp", Gio::APPLICATION_FLAGS_NONE) {
    set_application_name("c++ 专项练习");
}

Glib::RefPtr<MainApplication> MainApplication::create() {
    return Glib::RefPtr<MainApplication>(new MainApplication());
}

void MainApplication::on_activate() {
    window = create_window();
    window->present();
}

MainWindow *MainApplication::create_window() {
    window = MainWindow::create();
    auto builder = Gtk::Builder::create_from_resource("/window.glade");
    //    GtkApplicationWindow *sss = nullptr;
    //    auto window = new MainWindow(sss, builder);
    builder->get_widget_derived("window", window);
    add_window(*window);
    window->signal_hide().connect(sigc::bind(
                                      sigc::mem_fun(*this, &MainApplication::on_hide_window), window));

    cout<<"world"<<endl;



    return window;
}

void MainApplication::on_hide_window(Gtk::Window *window) {
    cout << "bye !!!" << endl;
    delete window;
}
