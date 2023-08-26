#ifndef MENUMODEL_H
#define MENUMODEL_H

#include <gtkmm.h>
#include <vector>
//#include <string>

using namespace std;
using namespace Glib;

class ModelColumns : public Gtk::TreeModel::ColumnRecord {
public:
  ModelColumns() {
    add(chapter);
    add(identifier);
    add(description);
    //            add(priority);dddddddddddds
  }

  Gtk::TreeModelColumn<ustring> chapter;
  Gtk::TreeModelColumn<ustring> identifier;
  Gtk::TreeModelColumn<ustring> description;
  //        Gtk::TreeModelColumn<uint8_t> priority;
};

class MenuModel {
public:
  MenuModel();
  RefPtr<Gtk::TreeStore> model;

private:
  using MenuNode = struct {
    ustring chapter;
    ustring identifier;
    ustring description;
  };
};

#endif // MENU_H
