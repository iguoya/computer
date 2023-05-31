cmake_minimum_required(VERSION 3.5) #设置CMake最小版本
project (c++) #设置工程名
set(PROJECT_TARGET c++)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

set(SOURCES
  main.cpp
  window.glade
)

#add_executable(c++ main.cpp) #生成可执行文件
# Create the executable
add_executable(${PROJECT_TARGET} ${SOURCES})
target_link_libraries(${PROJECT_TARGET} PRIVATE ${GTKMM_LIBRARIES})

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
target_include_directories(${PROJECT_TARGET} PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_directories(${PROJECT_TARGET} PRIVATE ${GTKMM_LIBRARY_DIRS})
target_compile_options(${PROJECT_TARGET} PRIVATE ${GTKMM_CFLAGS_OTHER})

message("hello")
file(COPY window.glade DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
