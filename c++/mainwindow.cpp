#include "mainwindow.h"



MainWindow::MainWindow(BaseObjectType *cobject,
                       const Glib::RefPtr<Gtk::Builder> &refBuilder)
    : Gtk::Window(cobject), builder(refBuilder) {}

MainWindow *MainWindow::create() {
  auto builder = Gtk::Builder::create_from_resource("/window.glade");
//  auto window =
//      Gtk::Builder::get_widget_derived<MainWindow>(builder, "main_window");
    MainWindow *  window = nullptr;
    builder->get_widget_derived("window", window);
//
//  builder->get_widget_derived("window", window);
//  if (!window) {
//      throw std::runtime_error("No \"window\" object in window.glade");
//  }


  if (!window)
    throw std::runtime_error("No \"app_window\" object in main_window.ui");

  auto styleProvider = Gtk::CssProvider::create();
  styleProvider->load_from_resource("/style.css");

  auto screen = Gdk::Display::get_default();
  auto context = window->get_style_context();

//  context->add_provider_for_display(screen, styleProvider, 800);

  return window;
}



//MainWindow::MainWindow()
//    :Application("cn.yatiger.cxx", Gio::APPLICATION_FLAGS_NONE)
//{
//    set_application_name("c++ 专项练习");
//}

//void MainWindow::on_startup()
//{
//    Application::on_startup();
////    builder = Builder::create();
//     builder = Gtk::Builder::create_from_resource("/window.glade");
////    try {
////        builder->add_from_file("/window.glade");

////    } catch (const Glib::Error &ex) {
////        MessageDialog dialog("Error building UI: " + ex.what());
////        dialog.run();
////    }
//}

//void MainWindow::on_activate()
//{
//    builder->get_widget("window", window);
//    builder->get_widget("treeview_menu", menu);
//    builder->get_widget("textview", textView);

//    textBuffer = TextBuffer::create();
//    textView->set_buffer(textBuffer);


//    //    builder->get_widget_derived("textbuffer", textBuffer);


//    menu->set_model(menuModel.getModel());
//    menu->expand_all();

//    menu->get_selection()->signal_changed().connect(
//                sigc::mem_fun(*this, &MainWindow::on_selected)
//                );


//    window->set_default_size(1200, 800);
//    add_window(*window);
//    window->show_all();
//}

//void MainWindow::on_selected()
//{
//    //    cout<<"hello"<<endl;
//    auto iter = menu->get_selection()->get_selected();
//    if(iter) //If anything is selected
//    {
//        auto row = *iter;
//        //        ustring chapter;
//        //        ustring identifier;
//        //        ustring description;

//        textBuffer->insert_at_cursor("This is the text from TextBuffer #AAA.");
//        textBuffer->insert_at_cursor("This is the text from TextBuffer #BBBB.");
//        textBuffer->insert_at_cursor("This is the text from TextBuffer #CCC.");
//        textBuffer->insert_at_cursor("This is the text from TextBuffer #DDDD.");


//        cout<< row[column.chapter]
//                <<"-----"
//               << row[column.identifier] <<"-----"
//               << row[column.description] <<"-----"
//               << std::endl;

//        auto chapter = Factory::create("auto");
//        chapter->run();


//        //        if(product != nullptr) {
//        //            product->s_notice.connect(sigc::mem_fun(*this, &MainWindow::notice));
//        //            product->s_display.connect(sigc::mem_fun(*this, &MainWindow::display));

//        //            product->s_set_columns.connect(sigc::mem_fun(*this, &MainWindow::setTableColumns));
//        //            product->s_display_table.connect(sigc::mem_fun(*this, &MainWindow::displayTable));
//        //            product->run();
//        //        }
//    }
//}


