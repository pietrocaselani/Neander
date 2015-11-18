cmake_minimum_required(VERSION 3.3)
project(Sample)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(NEANDER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../Neander)

if(APPLE)
    link_libraries(${NEANDER_PATH}/libneander.dylib)
elseif(UNIX)
    link_libraries(${NEANDER_PATH}/libneander.so)
else()
    link_libraries(${NEANDER_PATH}/libneander.dll)
endif()

include_directories(${NEANDER_PATH})

set(SOURCE_FILES main.cpp)
add_executable(Sample ${SOURCE_FILES})