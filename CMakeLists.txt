cmake_minimum_required(VERSION 3.29)
project(PingPong)

set(CMAKE_CXX_STANDARD 20)

if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(PingPong main.cpp
        Ball.h
        Ball.cpp
        Player.cpp
        Player.h)

target_link_libraries(PingPong PRIVATE SFML::Graphics SFML::Window SFML::System)
