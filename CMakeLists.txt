cmake_minimum_required(VERSION 3.12.0)

project(GeneralsBot)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)

set(SOURCES
	src/main.cpp
	src/Bot.cpp
)

include_directories("${PROJECT_SOURCE_DIR}/socket.io-client-cpp")
include_directories("${PROJECT_SOURCE_DIR}/socket.io-client-cpp/src")
add_subdirectory(socket.io-client-cpp)

add_executable(GeneralsBot ${SOURCES})

set_property(TARGET GeneralsBot PROPERTY CXX_STANDARD 11)
set_property(TARGET GeneralsBot PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(GeneralsBot
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(GeneralsBot sioclient pthread)
