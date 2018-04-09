cmake_minimum_required(VERSION 3.0)
project(Card_System)

set(CMAKE_CXX_STANDARD 11)

set(SRC_LIST tests.cpp tests.h Base_Card_Reader.h Readers.h Decorators.h Base_Card.h CCard.h)


set(CMAKE_BUILD_TYPE Release)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(Card_System ${SRC_LIST})

target_link_libraries(Card_System ${GTEST_LIBRARIES} pthread)
