#include "mainwindow.h"

MainWindow::MainWindow(GtkApplicationWindow *cobject,
                       const Glib::RefPtr<Gtk::Builder> &refBuilder)
    : Gtk::ApplicationWindow(cobject), builder(refBuilder) {
    //    builder = Gtk::Builder::create_from_resource("/window.glade");
    //        MainWindow* window = nullptr;
    //    builder->get_widget("window", window);
    builder->get_widget("treeview_menu", menu);
    builder->get_widget("textview", textView);

    textBuffer = TextBuffer::create();
    textView->set_buffer(textBuffer);

    menu->set_model(menuModel.getModel());
    menu->expand_all();

    menu->get_selection()->signal_changed().connect(
                sigc::mem_fun(*this, &MainWindow::on_selected)
                );


    set_default_size(1600, 1200);

    //        auto styleProvider = Gtk::CssProvider::create();
    //        styleProvider->load_from_resource("/style.css");

    //        auto screen = Gdk::Display::get_default();
    //        auto context = window->get_style_context();

    //  context->add_provider_for_display(screen, styleProvider, 800);
}




void MainWindow::on_selected()
{
    //    cout<<"hello"<<endl;
    auto iter = menu->get_selection()->get_selected();
    if(iter) //If anything is selected
    {
        auto row = *iter;
        //        ustring chapter;
        //        ustring identifier;
        //        ustring description;

        textBuffer->insert_at_cursor("This is the text from TextBuffer #AAA.\n");
        textBuffer->insert_at_cursor("This is the text from TextBuffer #BBBB.\n");
        textBuffer->insert_at_cursor("This is the text from TextBuffer #CCC.\n");
        textBuffer->insert_at_cursor("This is the text from TextBuffer #DDDD.\n");


        cout<< row[column.chapter]
               <<"-----"
               << row[column.identifier] <<"-----"
               << row[column.description] <<"-----"
               << std::endl;

        auto chapter = Factory::create("auto");
        chapter->run();


        //        if(product != nullptr) {
        //            product->s_notice.connect(sigc::mem_fun(*this, &MainWindow::notice));
        //            product->s_display.connect(sigc::mem_fun(*this, &MainWindow::display));

        //            product->s_set_columns.connect(sigc::mem_fun(*this, &MainWindow::setTableColumns));
        //            product->s_display_table.connect(sigc::mem_fun(*this, &MainWindow::displayTable));
        //            product->run();
        //        }
    }
}


