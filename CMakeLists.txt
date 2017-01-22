cmake_minimum_required(VERSION 3.2)
project(rush01)

include_directories(headers)
include_directories(SFML_2.4.1)

set(SOURCE_FILES
    srcs/main.cpp
    srcs/SfmlDisplay.class.cpp
    srcs/Monitor.class.cpp
    srcs/ModuleName.class.cpp
    headers/IMonitorDisplay.class.hpp
    headers/SfmlDisplay.class.hpp
    headers/Monitor.class.hpp
    headers/IMonitorModule.class.hpp
    headers/ModuleName.class.hpp
    )
add_executable(rush01 ${SOURCE_FILES})
