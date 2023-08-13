#ifndef MENUMODEL_H
#define MENUMODEL_H

#include <gtkmm.h>
#include <vector>
//#include <string>

using namespace std;
using namespace Glib;
using namespace Gtk;


class ModelColumns : public Gtk::TreeModel::ColumnRecord
{
public:
    ModelColumns() {
        add(chapter);
        add(identifier);
        add(description);
        //            add(priority);
    }

    Gtk::TreeModelColumn<ustring> chapter;
    Gtk::TreeModelColumn<ustring> identifier;
    Gtk::TreeModelColumn<ustring> description;
    //        Gtk::TreeModelColumn<uint8_t> priority;
};


class MenuModel
{
public:
    MenuModel();

    RefPtr<Gtk::TreeStore> getModel();

//private:
    RefPtr<Gtk::TreeStore> model;
    using MenuNode = struct {
    ustring chapter;
    ustring identifier;
    ustring description;
};

};

#endif // MENU_H
