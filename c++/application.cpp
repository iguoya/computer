#include "application.h"

Application::Application() : Gtk::Application("cn.yatiger.c++")
{

}

Glib::RefPtr<Application> Application::create() {
     return Glib::RefPtr<Application>(new Application());
}

MainWindow* Application::create_window() {
  auto window = MainWindow::create();

  add_window(*window);
  window->signal_hide().connect(sigc::bind(sigc::mem_fun(*this, &Application::on_hide_window), window));

  return window;
}

void Application::on_activate() {
  auto window = create_window();
  window->present();
}

void Application::on_hide_window(Gtk::Window* window) {
  delete window;
}
