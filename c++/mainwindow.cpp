#include "mainwindow.h"

MainWindow* MainWindow::window;
MainWindow::MainWindow(GtkApplicationWindow *cobject,
                       const Glib::RefPtr<Gtk::Builder> &refBuilder)
    : Gtk::ApplicationWindow(cobject), builder(refBuilder) {
    set_default_size(1600, 1200);

    builder->get_widget("treeview_menu", menu);
    menu->set_model(menuModel.model);

    builder->get_widget("textview", textView);
    textBuffer = Glib::RefPtr<Gtk::TextBuffer>::cast_dynamic(
                builder->get_object("textbuffer"));
    //    textBuffer = Gtk::TextBuffer::create();
    textView->set_buffer(textBuffer);



    menu->expand_all();
    menu->get_selection()->signal_changed().connect(
                sigc::mem_fun(*this, &MainWindow::on_selected));


    TModelColumns tm;
    //    //    RefPtr<Gtk::TreeStore> list_store;


    //    listStore =  RefPtr<Gtk::ListStore>::cast_dynamic(
    //                builder->get_object("liststore"));
    listStore = Gtk::ListStore::create(tm);


    //    listStore->

    //    //    //Fill the TreeView's model
    auto row = *(listStore->append());
    //    row[tm.name] = "Billy Bob";
    //    row[tm.age] = "1";
    row.set_value<ustring>(0, "Billy Bob");
    row.set_value<ustring>(1, "111");
    row = *(listStore->append());
    row[tm.name] = "Lisa";
    row[tm.age] = "27";

    builder->get_widget("listview", listView);
    listView->set_model(listStore);
    listView->append_column("namesss", tm.name);
    listView->append_column("age", tm.age);

    //    row = *(listStore->append());


    //    listView->set_model(listStore);
    //    row = *(m_refTreeModel->append());
    //    row[m_Columns.m_col_id] = 2;
    //    row[m_Columns.m_col_name] = "Joey Jojo";
    //    row[m_Columns.m_col_number] = 20;
    //    row[m_Columns.m_col_percentage] = 40;

    //    row = *(m_refTreeModel->append());
    //    row[m_Columns.m_col_id] = 3;
    //    row[m_Columns.m_col_name] = "Rob McRoberts";
    //    row[m_Columns.m_col_number] = 30;
    //    row[m_Columns.m_col_percentage] = 70;

    //    //Add the TreeView's view columns:
    //    //This number will be shown with the default numeric formatting.
    //    m_TreeView.append_column("ID", m_Columns.m_col_id);
    //    m_TreeView.append_column("Name", m_Columns.m_col_name);

    //    m_TreeView.append_column_numeric("Formatted number", m_Columns.m_col_number,
    //            "%010d" /* 10 digits, using leading zeroes. */);

    //    //Display a progress bar instead of a decimal number:
    //    auto cell = Gtk::make_managed<Gtk::CellRendererProgress>();
    //    int cols_count = m_TreeView.append_column("Some percentage", *cell);
    //    auto pColumn = m_TreeView.get_column(cols_count - 1);
    //    if(pColumn)
    //    {
    //      pColumn->add_attribute(cell->property_value(), m_Columns.m_col_percentage);
    //    }

    //    //Make all the columns reorderable:
    //    //This is not necessary, but it's nice to show the feature.
    //    //You can use TreeView::set_column_drag_function() to more
    //    //finely control column drag and drop.
    //    for(guint i = 0; i < 2; i++)
    //    {
    //      auto column = m_TreeView.get_column(i);
    //      column->set_reorderable();
    //    }

    show_all_children();


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
        cout << row[column.name] << "-----" << "-----"
                                 << row[column.description] << "-----" << std::endl;

        //        using ss = row[column.identifier];
        auto product = Factory::create(row.get_value(column.identifier));
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
}

//void MainWindow::display(vector<Row> result)
//{
//    for(const auto &m : result) {
//        auto row = *(resultModel->append());
//        //        row[m_Columns.id] = m.id;
//        //        row[m_Columns.name] = m.name;
//        //        row[m_Columns.input] = m.input;
//        //        row[m_Columns.result] = m.result;
//    }
//    //      //Fill the TreeView's model
//    //      auto row = *(resultModel->append());
//    //      row[m_Columns.id] = 1;
//    //      row[m_Columns.name] = "Billy Bob";
//}



