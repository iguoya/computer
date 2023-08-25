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
//    RefPtr<Gtk::Builder> builder;
    static MainWindow* window;
    MainWindow* create_window();
    void on_hide_window(Gtk::Window* window);
};


//#include <gtkmm/application.h>
//#include <glibmm/refptr.h>
//#include <giomm/settings.h>
//#include "mainwindow.h"

//class Application : public Gtk::Application
//{
//public:
////    Application();

//    static Glib::RefPtr<Application> create();

//protected:
//    Application();

//    void on_activate() override;

//private:
//    MainWindow* create_window();
//    void on_hide_window(Gtk::Window* window);
//};

#endif // MAINAPPLICATION_H
