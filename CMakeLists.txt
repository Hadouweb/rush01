cmake_minimum_required(VERSION 3.2)
project(rush01)

include_directories(headers)
include_directories(SF)

set(SOURCE_FILES
    srcs/main.cpp
    srcs/SfmlDisplay.class.cpp
    srcs/Monitor.class.cpp
    srcs/ModuleName.class.cpp
    srcs/ModuleOsInfo.class.cpp
    srcs/NcursesDisplay.class.cpp
    srcs/ModuleCpu.class.cpp
    srcs/ModuleRam.class.cpp
    srcs/ModuleTime.class.cpp
    headers/IMonitorDisplay.class.hpp
    headers/SfmlDisplay.class.hpp
    headers/Monitor.class.hpp
    headers/IMonitorModule.class.hpp
    headers/ModuleName.class.hpp
    headers/ModuleOsInfo.class.hpp
    headers/NcursesDisplay.class.hpp
    headers/ModuleCpu.class.hpp
    headers/ModuleTime.class.hpp
    headers/ModuleRam.class.hpp
    )
add_executable(rush01 ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(rush01 ${SFML_LIBRARIES})
endif()