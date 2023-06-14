#include "menumodel.h"

MenuModel::MenuModel()
{
    ModelColumns columns;
    model = TreeStore::create(columns);

    vector<pair<MenuNode, vector<MenuNode>>> menu {
        {
            {"关键字用法", "keywords", ""},
            {
                {"Auto", "auto", "ssss"},
                {"decltype", "const", "vvvvv"},
                {"using", "const", "vvvvv"},
                {"lambda", "const", "vvvvv"},
                {"const", "const", "vvvvv"},
                {"constexpr", "const", "vvvvv"},
                {"move", "const", "vvvvv"},
                {"nullptr", "const", "vvvvv"},
                {"shared_ptr", "const", "vvvvv"},
                {"unique_ptr", "const", "vvvvv"},
                {"weak_ptr", "const", "vvvvv"},
            }
        },
        {
            {"高级用法", "grammar", ""},
            {
                {"函数指针", "FunctionPointer", ""},
                {"Auto", "auto", "dddd"},
                {"Const", "const", "1"},
            }
        },
        {
            {"标准模板库", "grammar", ""},
            {
                {"FunctionPointer", "函数指针", ""},
                {"Auto", "auto", "dddd"},
                {"Const", "const", "1"},
            }
        },
        {
            {"算法与迭代器", "grammar", ""},
            {
                {"FunctionPointer", "函数指针", ""},
                {"Auto", "auto", "dddd"},
                {"Const", "const", "1"},
            }
        },
        {
            {"类和对象", "grammar", ""},
            {
                {"FunctionPointer", "函数指针", ""},
                {"Auto", "auto", "dddd"},
                {"Const", "const", "1"},
            }
        },
        {
            {"继承和派生", "grammar", ""},
            {
                {"FunctionPointer", "函数指针", ""},
                {"Auto", "auto", "dddd"},
                {"Const", "const", "1"},
            }
        },
        {
            {"模板与泛型", "grammar", ""},
            {
                {"FunctionPointer", "函数指针", ""},
                {"Auto", "auto", "dddd"},
                {"Const", "const", "1"},
            }
        },
        {
            {"并发与多线程", "grammar", ""},
            {
                {"FunctionPointer", "函数指针", ""},
                {"Auto", "auto", "dddd"},
                {"Const", "const", "1"},
            }
        },
        {
            {"内存管理", "grammar", ""},
            {
                {"FunctionPointer", "函数指针", ""},
                {"Auto", "auto", "dddd"},
                {"Const", "const", "1"},
            }
        },
        {
            {"高级话题/新标准", "grammar", ""},
            {
                {"FunctionPointer", "函数指针", ""},
                {"Auto", "auto", "dddd"},
                {"Const", "const", "1"},
            }
        },

    };


    for(auto section : menu) {
        TreeModel::Row row = *(model->append());
        row[columns.chapter] = section.first.chapter;
        row[columns.identifier] = section.first.identifier;
        row[columns.description] = section.first.description;
        for(auto item : section.second) {
            Gtk::TreeModel::Row child = *(model->append(row.children()));
            child[columns.chapter] = item.chapter;
            child[columns.identifier] = item.identifier;
            child[columns.description] = item.description;
        }
    }

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
    //                {"Auto", "auto"}, {"Const", "const"},
    //            }
    //        }

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
