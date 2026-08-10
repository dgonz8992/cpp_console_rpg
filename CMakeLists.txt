cmake_minimum_required(VERSION 4.1)
project(cpp_console_rpg)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cpp_console_rpg
        Source/main.cpp
        Source/Characters/Character.cpp
        Source/Characters/Character.h
        Source/Items/Item.cpp
        Source/Items/Item.h
        Source/Characters/Player.cpp
        Source/Characters/Player.h
        Source/Items/Potion.cpp
        Source/Items/Potion.h
        Source/RNG.cpp
        Source/Items/Sword.cpp
        Source/Items/Sword.h
        Source/Characters/Backpack.cpp
        Source/Characters/Backpack.h
        Source/Items/Store.cpp
        Source/Items/Store.h
)

target_include_directories(cpp_console_rpg PUBLIC
        Source
        Source/Characters
        Source/Items
)