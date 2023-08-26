#include "mainwindow.h"

MainWindow* MainWindow::window;
MainWindow::MainWindow(GtkApplicationWindow *cobject,
                       const Glib::RefPtr<Gtk::Builder> &refBuilder)
    : Gtk::ApplicationWindow(cobject), builder(refBuilder) {
    set_default_size(1600, 1200);
    builder->get_widget("treeview_menu", menu);
    builder->get_widget("textview", textView);

    textBuffer = Gtk::TextBuffer::create();
    textView->set_buffer(textBuffer);
    menu->set_model(menuModel.model);
    menu->expand_all();
    menu->get_selection()->signal_changed().connect(
                sigc::mem_fun(*this, &MainWindow::on_selected));

    //        auto styleProvider = Gtk::CssProvider::create();
    //        styleProvider->load_from_resource("/style.css");

    //        auto screen = Gdk::Display::get_default();
    //        auto context = window->get_style_context();

    //  context->add_provider_for_display(screen, styleProvider, 800);
}

MainWindow* MainWindow::create()
{
    auto builder = Gtk::Builder::create_from_resource("/window.glade");
    builder->get_widget_derived("window", window);
    return window;
}

void MainWindow::on_selected() {
    static int count = 0;
    auto iter = menu->get_selection()->get_selected();
    if (iter) // If anything is selected
    {
        cout<<count<<endl;
        auto row = *iter;
        //        ustring chapter;
        //        ustring identifier;
        //        ustring description;
        cout << row[column.chapter] << "-----" << row[column.identifier] << "-----"
                                    << row[column.description] << "-----" << std::endl;

        //        using ss = row[column.identifier];
        auto product = Factory::create(row.get_value(column.identifier).raw());
        //        chapter->run();

        //        sigc::signal<void(const string &)> display;
        //        sigc::signal<void(const vector<string> &)> displays;

        //        sigc::signal<void(const vector<string> &)> set_columns;
        //        sigc::signal<void(const vector<vector<string>> &)> display_table;



        if(product != nullptr) {
            product->display.connect(sigc::mem_fun(*this,
                                                   &MainWindow::display));
            //            product->displays.connect(sigc::mem_fun(*this,
            //                                                     &MainWindow::display));

            //            product->set_columns.connect(sigc::mem_fun(*this,
            //                                                         &MainWindow::setTableColumns));
            //            product->display_table.connect(sigc::mem_fun(*this,
            //                                                           &MainWindow::displayTable));
            product->run();
        }
    }
}



void MainWindow::display(string msg)
{
    textBuffer->insert_at_cursor(msg+"\n");
    //    Gtk::TextBuffer::iterator iter;
    //    iter = textBuffer->get_iter_at_offset(0);
    //    iter = textBuffer->insert(iter, msg);
//    auto iter_end = textBuffer->get_iter_at_offset(textBuffer->get_char_count());
//    textBuffer->insert(iter_end, ustring(msg+"\n"));

    //    textBuffer->insert_at_cursor(ustring(msg+"\n"));
    //    textView->scroll_to(m_endMark);
    //    textBuffer->set_text(msg);
    //    textBuffer->insert(iter_end, ustring(msg+"\n"));
    //    textBuffer->set_text(ustring(msg));
    //    textView->scroll_to(m_endMark);
}




