#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm.h>


class MainWindow : public Gtk::Window
{
public:
    MainWindow(BaseObjectType* obj, Glib::RefPtr<Gtk::Builder> const& builder)
        : Gtk::Window(obj)
        , builder{builder}
    {

    }
    virtual ~MainWindow() = default;
private:
    Glib::RefPtr<Gtk::Builder> builder;
};


//class MainWindow  : public Gtk::Window
//{
//public:
//    MainWindow(BaseObjectType* parent = nullptr);

////    {
////        if(ui) {
////            ui->get_widget("window", window);
////            set_default_size(1000, 600);
////        }

//////        set_title("hello");
//////        show_all_children();
////        show_all();
////    };

//protected:
//    Glib::RefPtr<Gtk::Builder> ui;
//    Gtk::Window* window;
//};



#endif // MAINWINDOW_H
