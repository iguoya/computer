#cmake_minimum_required(VERSION 3.5) #设置CMake最小版本
cmake_minimum_required(VERSION 3.13)

set(PROJECT_TARGET c++)


project(c++
    VERSION 1.0
    DESCRIPTION "c++ 专项练习"
    LANGUAGES CXX) #设置工程名

configure_file(resources/window.glade resources/window.glade COPYONLY)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

#file(GLOB SOURCES "*.cpp")
message(${CMAKE_CURRENT_SOURCE_DIR})

FILE(GLOB_RECURSE LibFiles "*.h")
add_custom_target(headers SOURCES ${LibFiles})

add_executable(c++
    main.cpp
    mainwindow.cpp
    menumodel.cpp
    resources/window.glade
)

#target_link_libraries(${PROJECT_TARGET} PRIVATE gui)

#install(TARGETS ${PROJECT_TARGET}
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_check_modules(SIGCPP REQUIRED sigc++-2.0)
pkg_check_modules(GLIB REQUIRED glib-2.0)


#include_directories(
#    ${GLIB_INCLUDE_DIRS}
#    ${SIGCPP_INCLUDE_DIRS}
#    ${GTKMM_INCLUDE_DIRS}
#    )

#add_executable(c++ main.cpp) #生成可执行文件
# Create the executable
#add_executable(${PROJECT_TARGET} ${SOURCES})
#target_link_libraries(${PROJECT_TARGET} PRIVATE ${GTKMM_LIBRARIES})

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
target_include_directories(${PROJECT_TARGET} PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_directories(${PROJECT_TARGET} PRIVATE ${GTKMM_LIBRARY_DIRS})
target_compile_options(${PROJECT_TARGET} PRIVATE ${GTKMM_CFLAGS_OTHER})

target_link_libraries(${PROJECT_TARGET}
        ${SIGCPP_LIBRARIES}
        ${GTKMM_LIBRARIES}
        ${GLIB_LDFLAGS}
        )


#file(COPY window.glade DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
