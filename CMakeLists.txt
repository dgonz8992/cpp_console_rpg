cmake_minimum_required(VERSION 4.1)
project(cpp_console_rpg)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_console_rpg main.cpp
        Character.cpp
        Character.h
        Item.cpp
        Item.h
        Player.cpp
        Player.h
        Potion.cpp
        Potion.h
        RNG.cpp
)