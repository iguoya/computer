#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <gtkmm.h>
#include "mainwindow.h"

class MainApplication : public Gtk::Application
{
public:
    MainApplication();

    static Glib::RefPtr<MainApplication> create();

protected:

    void on_activate() override;

private:

    static MainWindow* window;

    MainWindow* create_window();
    void on_hide_window(Gtk::Window* window);

};

#endif // MAINAPPLICATION_H
