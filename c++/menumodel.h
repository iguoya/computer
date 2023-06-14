#ifndef MENUMODEL_H
#define MENUMODEL_H

#include <gtkmm.h>
#include <vector>
//#include <string>

using namespace std;
using namespace Glib;
using namespace Gtk;


class ModelColumns : public TreeModel::ColumnRecord
{
public:
    ModelColumns() {
        add(chapter);
        add(identifier);
        add(description);
        //            add(priority);
    }

    TreeModelColumn<ustring> chapter;
    TreeModelColumn<ustring> identifier;
    TreeModelColumn<ustring> description;
    //        TreeModelColumn<uint8_t> priority;
};


class MenuModel
{
public:
    MenuModel();

    RefPtr<TreeStore> getModel();

//private:
    RefPtr<TreeStore> model;
    using MenuNode = struct {
    ustring chapter;
    ustring identifier;
    ustring description;
};

};

#endif // MENU_H
