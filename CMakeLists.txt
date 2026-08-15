cmake_minimum_required(VERSION 3.20)
project(Chess)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR
        "C:/Users/eriii/Downloads/SFML-3.1.0-windows-gcc-14.2.0-mingw-64-bit/SFML-3.1.0/lib/cmake/SFML"
)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(Chess src/main/main.cpp
        src/constants/Constants.h
        src/window/Window.cpp
        src/window/Window.h)

target_link_libraries(Chess PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)