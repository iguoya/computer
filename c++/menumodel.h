#ifndef MENUMODEL_H
#define MENUMODEL_H

#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class MenuModel
{
public:
    MenuModel();

    RefPtr<TreeStore> getModel();

    class ModelColumns : public TreeModel::ColumnRecord
    {
    public:
        ModelColumns() {
            add(chapter);
            add(identifier);
            add(priority);
        }

        TreeModelColumn<ustring> chapter;
        TreeModelColumn<ustring> identifier;
        TreeModelColumn<uint8_t> priority;
    };
private:
    RefPtr<TreeStore> model;
};

#endif // MENU_H
