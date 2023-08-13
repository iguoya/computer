#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <gtkmm.h>
#include "mainwindow.h"

class MainApplication : public Gtk::Application
{
public:
    MainApplication();

public:
    static Glib::RefPtr<MainApplication> create();

protected:
    //  Application();

    void on_activate() override;

private:
    MainWindow* create_window();
    void on_hide_window(Gtk::Window* window);

};

#endif // MAINAPPLICATION_H
