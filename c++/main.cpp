#include <gtkmm.h>

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv,
                                        "org.gtkmm.examples.base");

    //    auto refBuilder = Gtk::Builder::create();
    auto builder = Gtk::Builder::create_from_file("window.glade");

    //    void* window;
    Gtk::Window* window;
    builder->get_widget("window", window);

    return app->run(*window);
            //    Gtk::ApplicationWindow window;
            //    return app->run(window);
}
