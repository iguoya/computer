#cmake_minimum_required(VERSION 3.5) #设置CMake最小版本
cmake_minimum_required(VERSION 3.10)

set(target c++)

project(c++
    VERSION 1.0
    DESCRIPTION "c++ 专项练习"
    LANGUAGES CXX) #设置工程名





#set(
#  RESOURCE_LIST
#  style.css
#  main_window.ui
#)

#compile_gresources(RESOURCE_FILE XML_OUT TYPE EMBED_C RESOURCES ${RESOURCE_LIST} SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets)

#include_directories("src/include")
#add_executable(
#  ${PROJECT_NAME}
#  "src/main.cpp"
#  "src/window.cpp"
#  "src/application.cpp"
#  ${RESOURCE_FILE}
#)

#target_link_libraries(${PROJECT_NAME} PUBLIC PkgConfig::GTKMM)






configure_file(resources/window.glade resources/window.glade COPYONLY)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

#file(GLOB SOURCES "*.cpp")
message(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(framework/)
include_directories(keyword/)

#FILE(GLOB_RECURSE LibFiles "*.h")

#add_custom_target(headers SOURCES ${LibFiles})

add_executable(c++
    main.cpp
    mainwindow.cpp
    menumodel.cpp
    framework/chapter.cpp
    framework/factory.cpp
    keyword/auto.h keyword/auto.cpp
    resources/window.glade
)

#target_link_libraries(${target} PRIVATE gui)

#install(TARGETS ${target}
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_check_modules(SIGCPP REQUIRED sigc++-2.0)
pkg_check_modules(GLIB REQUIRED glib-2.0)

list(
  APPEND CMAKE_MODULE_PATH
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/macros
)
include(GlibCompileResourcesSupport)
set(
  RESOURCE_LIST
  style.css
  main_window.ui
)

compile_gresources(RESOURCE_FILE XML_OUT TYPE EMBED_C RESOURCES ${RESOURCE_LIST} SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets)

include_directories(
    ${GLIB_INCLUDE_DIRS}
    ${SIGCPP_INCLUDE_DIRS}
    ${GTKMM_INCLUDE_DIRS}
    )

target_compile_options(${target} PRIVATE ${GTKMM_CFLAGS_OTHER})

target_link_libraries(
    ${target}
    ${SIGCPP_LIBRARIES}
    ${GTKMM_LIBRARIES}
    ${GLIB_LDFLAGS}
)


#file(COPY window.glade DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
