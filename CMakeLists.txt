cmake_minimum_required(VERSION 3.2)
project(rush01)

set(SOURCE_FILES srcs/main.cpp)
add_executable(rush01 ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(rush01 ${SFML_LIBRARIES})
endif()