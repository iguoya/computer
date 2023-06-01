#cmake_minimum_required(VERSION 3.5) #设置CMake最小版本
cmake_minimum_required(VERSION 3.25)
#project ()
set(PROJECT_TARGET c++)

project(c++ LANGUAGES CXX) #设置工程名

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

#include_directories(.)
#file(GLOB SOURCES "*.cpp")
#window.glade
message(${CMAKE_CURRENT_SOURCE_DIR})
#set(sources
#    ${CMAKE_CURRENT_SOURCE_DIR}/
#    ${CMAKE_CURRENT_SOURCE_DIR}/
#    ${CMAKE_CURRENT_SOURCE_DIR}/)

add_executable(c++
    main.cpp
    window.glade
    mainwindow.h
    mainwindow.cpp
)

#add_library(gui
#    window.h
#    window.cpp
#)
#target_link_libraries(${PROJECT_TARGET} PRIVATE gui)

install(TARGETS ${PROJECT_TARGET}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

#set(SOURCES

#)

#add_executable(c++ main.cpp) #生成可执行文件
# Create the executable
#add_executable(${PROJECT_TARGET} ${SOURCES})
target_link_libraries(${PROJECT_TARGET} PRIVATE ${GTKMM_LIBRARIES})

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
target_include_directories(${PROJECT_TARGET} PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_directories(${PROJECT_TARGET} PRIVATE ${GTKMM_LIBRARY_DIRS})
target_compile_options(${PROJECT_TARGET} PRIVATE ${GTKMM_CFLAGS_OTHER})

file(COPY window.glade DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
