cmake_minimum_required(VERSION 3.2)
project(rush01)

include_directories(headers)
include_directories(SF)

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

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(rush01 ${SFML_LIBRARIES})
endif()