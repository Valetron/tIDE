cmake_minimum_required(VERSION 3.10)

include(cmake/misc.cmake)
include(cmake/settings.cmake)
include(cmake/VJ_FindNcurses.cmake) # FIXME: переделать поиск?

project(tide
        VERSION 0.1
        DESCRIPTION "Terminal integrated development environment"
        HOMEPAGE_URL ""
        LANGUAGES CXX)

set(INCLUDES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/")
include_directories(${INCLUDES_DIR})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/settings.h.orig ${CMAKE_CURRENT_SOURCE_DIR}/include/settings.h COPYONLY)

add_subdirectory(src/)
