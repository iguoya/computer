#include "application.h"

MainWindow *Application::window;

Application::Application()
    : Gtk::Application("cn.yatiger.cpp", Gio::APPLICATION_FLAGS_NONE) {
    set_application_name("c++ 专项练习");
}

Glib::RefPtr<Application> Application::create() {
    return Glib::RefPtr<Application>(new Application());
}

void Application::on_activate() {
    window = create_window();
    window->present();
}

MainWindow *Application::create_window() {
    window = MainWindow::create();
    auto builder = Gtk::Builder::create_from_resource("/window.glade");
    //    GtkApplicationWindow *sss = nullptr;
    //    auto window = new MainWindow(sss, builder);
    builder->get_widget_derived("window", window);
    add_window(*window);
    window->signal_hide().connect(sigc::bind(
                                      sigc::mem_fun(*this, &Application::on_hide_window), window));

    cout<<"create window finish..."<<endl;
    return window;
}

void Application::on_hide_window(Gtk::Window *window) {
    cout << "bye !!!" << endl;
    delete window;
}
