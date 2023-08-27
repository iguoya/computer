#include "menumodel.h"

MenuModel::MenuModel() {
    ModelColumns columns;
    model = Gtk::TreeStore::create(columns);


//    enum class Identifier {
//        Keyword,
//        Auto,
//        Const,
//    };

    vector<pair<MenuNode, vector<MenuNode>>> menu {
        {{"关键字用法", Identifier::Keyword, ""},
            {
                {"auto", Identifier::Auto, "ssss"},
                {"decltype", Identifier::Const, "vvvvv"},
                {"using", Identifier::Const, "vvvvv"},
                {"lambda", Identifier::Const, "vvvvv"},
                {"const", Identifier::Const, "vvvvv"},
                {"constexpr", Identifier::Const, "vvvvv"},
                {"move", Identifier::Const, "vvvvv"},
                {"nullptr", Identifier::Const, "vvvvv"},
                {"shared_ptr", Identifier::Const, "vvvvv"},
                {"unique_ptr", Identifier::Const, "vvvvv"},
                {"weak_ptr", Identifier::Const, "vvvvv"},
            }},
//        {{"高级用法", "grammar", ""},
//            {
//                {"函数指针", "FunctionPointer", ""},
//                {"auto", Identifier::Auto, "dddd"},
//                {Identifier::Const, Identifier::Const, "1"},
//            }},
//        {{"标准模板库", "grammar", ""},
//            {
//                {"FunctionPointer", "函数指针", ""},
////                {"auto", Identifier::Auto, "dddd"},
////                {Identifier::Const, Identifier::Const, "1"},
//            }},
//        {{"算法与迭代器", "grammar", ""},
//            {
//                {"FunctionPointer", "函数指针", ""},
////                {Identifier::Auto, Identifier::Auto, "dddd"},
////                {Identifier::Const, Identifier::Const, "1"},
//            }},
//        {{"类和对象", "grammar", ""},
//            {
//                {"FunctionPointer", "函数指针", ""},
////                {Identifier::Auto, Identifier::Auto, "dddd"},
////                {Identifier::Const, Identifier::Const, "1"},
//            }},
//        {{"继承和派生", "grammar", ""},
//            {
//                {"FunctionPointer", "函数指针", ""},
//                {Identifier::Auto, Identifier::Auto, "dddd"},
//                {Identifier::Const, Identifier::Const, "1"},
//            }},
//        {{"模板与泛型", "grammar", ""},
//            {
//                {"FunctionPointer", "函数指针", ""},
//                {Identifier::Auto, Identifier::Auto, "dddd"},
//                {Identifier::Const, Identifier::Const, "1"},
//            }},
//        {{"并发与多线程", "grammar", ""},
//            {
//                {"FunctionPointer", "函数指针", ""},
////                {Identifier::Auto, Identifier::Auto, "dddd"},
////                {Identifier::Const, Identifier::Const, "1"},
//            }},
//        {{"内存管理", "grammar", ""},
//            {
//                {"FunctionPointer", "函数指针", ""},
////                {Identifier::Auto, Identifier::Auto, "dddd"},
////                {Identifier::Const, Identifier::Const, "1"},
//            }},
//        {{"高级话题/新标准", "grammar", ""},
//            {
//                {"FunctionPointer", "函数指针", ""},
////                {Identifier::Auto, Identifier::Auto, "dddd"},
////                {Identifier::Const, Identifier::Const, "1"},
//            }},

    };

    for (auto section : menu) {
        Gtk::TreeModel::Row row = *(model->append());
        row[columns.name] = section.first.name;
        row[columns.identifier] = section.first.identifier;
        row[columns.description] = section.first.description;
        for (auto item : section.second) {
            Gtk::TreeModel::Row child = *(model->append(row.children()));
            child[columns.name] = item.name;
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
    //                {Identifier::Auto, Identifier::Auto}, {Identifier::Const, Identifier::Const},
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

ModelColumns::ModelColumns()
{
    add(name);
    add(identifier);
    add(description);
    //            add(priority);dddddddddddds
}
