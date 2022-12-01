cmake_minimum_required(VERSION 3.23)
project(lab5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab5 main.cpp mainwindow.cpp mainwindow.h mainwindow.ui  output.cpp output.h input.cpp input.h)
target_link_libraries(lab5
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
