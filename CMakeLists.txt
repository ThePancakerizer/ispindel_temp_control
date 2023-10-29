cmake_minimum_required(VERSION 3.26)
project(gesallprov)

set(CMAKE_CXX_STANDARD 20)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS system)
find_package(Threads REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME}
            main.cpp
            config_parser.cpp
            tcp_connection.cpp
            plug_adapter.cpp
            plug_adapter.h
    )
    target_link_libraries(${PROJECT_NAME}
            ${Boost_LIBRARIES}
            ${CMAKE_THREAD_LIBS_INIT}
    )
endif()


