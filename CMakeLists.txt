cmake_minimum_required(VERSION 3.0)
project(Card_System)

set(CMAKE_CXX_STANDARD 11)




if(DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()

if (WITH_TEST)
    set(SRC_LIST tests.cpp tests.h Base_Card_Reader.h Readers.h Decorators.h Base_Card.h CCard.h)
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})
    add_executable(Card_System ${SRC_LIST})
    target_link_libraries(Card_System ${GTEST_LIBRARIES} pthread)
else()
    set(SRC_LIST main.cpp Base_Card_Reader.h Readers.h Decorators.h Base_Card.h CCard.h)
    add_executable(Card_System ${SRC_LIST})
endif()
find_package(Doxygen)
if (DOXYGEN_FOUND)

    
    message("Doxygen build started")
    add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
