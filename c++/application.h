#ifndef APPLICATION_H
#define APPLICATION_H

#include <gtkmm/application.h>
#include <glibmm/refptr.h>
#include <giomm/settings.h>
#include "mainwindow.h"

class Application : public Gtk::Application
{
public:
//    Application();

    static Glib::RefPtr<Application> create();

protected:
    Application();

    void on_activate() override;

private:
    MainWindow* create_window();
    void on_hide_window(Gtk::Window* window);
};

#endif // APPLICATION_H
