#include "mainwindow.h"


MainWindow::MainWindow()
    :Application("cn.yatiger.cxx", Gio::APPLICATION_FLAGS_NONE)
{
    set_application_name("c++ 专项练习");
}

void MainWindow::on_startup()
{
    Application::on_startup();
    builder = Builder::create();
    try {
        builder->add_from_file("resources/window.glade");
    } catch (const Glib::Error &ex) {
        MessageDialog dialog("Error building UI: " + ex.what());
        dialog.run();
    }
}

void MainWindow::on_activate()
{
    builder->get_widget("window", window);
    builder->get_widget("treeview_menu", menu);

    menu->set_model(menu_model.getModel());
    menu->expand_all();

    menu->get_selection()->signal_changed().connect(
                sigc::mem_fun(*this, &MainWindow::on_selected)
                );


    //    window->set_default_size(1200, 800);
    add_window(*window);
    window->show_all();
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


