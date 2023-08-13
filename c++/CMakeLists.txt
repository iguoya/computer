cmake_minimum_required(VERSION 3.10)

project(c++
    VERSION 1.0
    DESCRIPTION "c++ 专项练习"
    LANGUAGES CXX
) #设置工程名

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

message(${CMAKE_CURRENT_SOURCE_DIR})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_check_modules(SIGCPP REQUIRED sigc++-2.0)
pkg_check_modules(GLIB REQUIRED glib-2.0)

include_directories(
    ${GLIB_INCLUDE_DIRS}
    ${SIGCPP_INCLUDE_DIRS}
    ${GTKMM_INCLUDE_DIRS}
)

include_directories(framework/)
include_directories(keyword/)

list(
  APPEND CMAKE_MODULE_PATH
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/macros
)
include(GlibCompileResourcesSupport)
set(
  RESOURCE_LIST
  style.css
  main_window.ui
  window.glade
)

compile_gresources(RESOURCE_FILE XML_OUT TYPE EMBED_C RESOURCES ${RESOURCE_LIST} SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets)


add_executable(c++
    main.cpp
    mainapplication.cpp
    mainwindow.cpp
    menumodel.cpp
    framework/chapter.cpp
    framework/factory.cpp
    keyword/auto.h keyword/auto.cpp
    ${RESOURCE_FILE}
)


target_compile_options(${PROJECT_NAME} PRIVATE ${GTKMM_CFLAGS_OTHER})

target_link_libraries(
    ${PROJECT_NAME}
    ${SIGCPP_LIBRARIES}
    ${GTKMM_LIBRARIES}
    ${GLIB_LDFLAGS}
)





#file(COPY window.glade DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
