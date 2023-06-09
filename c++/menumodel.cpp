#include "menumodel.h"

MenuModel::MenuModel()
{
    ModelColumns columns;
    model = TreeStore::create(columns);

    TreeModel::Row row = *(model->append());
    row[columns.chapter] = "John";
    row[columns.identifier] = "中文描述";
    row[columns.priority] = 30;

    Gtk::TreeModel::Row childrow = *(model->append(row.children()));
    childrow[columns.priority] = 11;
    childrow[columns.chapter] = "Billy Bob Junior";

    childrow = *(model->append(row.children()));
    childrow[columns.priority] = 1222;
    childrow[columns.chapter] = "Sue Bob";


    //    menuModel = TreeStore::create(m_menuColumns);
    //    menu.set_model(menuModel);
    //    //    treeView.set_reorderable();
    //    vector<pair<string, vector<pair<string, string>>>> catalogue {
    //        {
    //            "基本功能", {
    //                {"HelloWorld", "HelloWorld"}
    //            },
    //        },
    //        {
    //            "语言特性", {
    //                {"Auto", "auto"}, {"Const", "const"},  {"FunctionPointer", "函数指针"}
    //            }
    //        }
    //        //        {"标准模板库", {"const", "函数指针"}},
    //        //        {"算法与迭代器", {"const", "函数指针"}},
    //        //        {"类和对象", {"const", "函数指针"}},
    //        //        {"继承和派生", {"const", "函数指针"}},
    //        //        {"模板与泛型", {"const", "函数指针"}},
    //        //        {"智能指针", {"const", "函数指针"}},
    //        //        {"并发与多线程", {"const", "函数指针"}},
    //        //        {"内存管理", {"const", "函数指针"}},
    //        //        {"高级话题/新标准", {"const", "函数指针"}},
    //    };

    //    for(auto chapter : catalogue) {
    //        auto row = *(menuModel->append());
    //        row[m_menuColumns.name] = chapter.first;
    //        for(auto item : chapter.second) {
    //            auto childrow = *(menuModel->append(row.children()));
    //            childrow[m_menuColumns.className] = item.first;
    //            childrow[m_menuColumns.name] = item.second;
    //        }
    //    }


}

RefPtr<TreeStore> MenuModel::getModel()
{
    return model;
}
