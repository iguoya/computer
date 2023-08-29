#cmake_minimum_required(VERSION 3.10)
#SET(CMAKE_CXX_COMPILER /usr/bin/clang++)
#SET(CMAKE_C_COMPILER /usr/bin/clang)
project(c++
    VERSION 1.0
    DESCRIPTION "c++ 专项练习"
    LANGUAGES CXX
    ) #设置工程名

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET (CMAKE_CXX_FLAGS                "-Wall")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
#message(${CMAKE_CURRENT_SOURCE_DIR})

#find_package(PkgConfig REQUIRED)
#pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
#pkg_check_modules(SIGCPP REQUIRED sigc++-2.0)
#pkg_check_modules(GLIB REQUIRED glib-2.0)
#include_directories(
#    ${GLIB_INCLUDE_DIRS}
#    ${SIGCPP_INCLUDE_DIRS}
#    ${GTKMM_INCLUDE_DIRS}
#    )
find_package(PkgConfig)
pkg_search_module(GTKMM REQUIRED gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
find_package(Boost REQUIRED COMPONENTS)
include_directories(${Boost_INCLUDE_DIR})

include_directories(framework/)
include_directories(keyword/)

list(
    APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/macros
    )
include(GlibCompileResourcesSupport)
set(
    RESOURCE_LIST
    style.css
    window.glade
    )
compile_gresources(RESOURCE_FILE XML_OUT TYPE EMBED_C RESOURCES ${RESOURCE_LIST} SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets)


add_executable(c++
    main.cpp
    application.cpp
    mainwindow.cpp
    menumodel.cpp
    framework/identifier.h
    framework/product.cpp
    framework/singleton.cpp
    framework/factory.cpp
    keyword/keyword.cpp
    keyword/auto.cpp
    keyword/const.cpp
    keyword/nullptr.cpp
    keyword/tuple.cpp

    ${RESOURCE_FILE}
    )
target_link_libraries(c++ ${GTKMM_LIBRARIES} ${Boost_LIBRARIES})
#target_compile_options(c++ PRIVATE ${GTKMM_CFLAGS_OTHER})
#target_link_libraries(
#    c++
#    ${SIGCPP_LIBRARIES}
#    ${GTKMM_LIBRARIES}
#    ${GLIB_LDFLAGS}
#    )
#file(COPY window.glade DESTINATION ${CMAKE_CURRENT_BINARY_DIR})






