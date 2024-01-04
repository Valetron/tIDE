if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "Create separate directory for build.")
endif()

if(NOT LINUX)
    message(FATAL_ERROR "Only Linux currently supported")
endif()

cmake_minimum_required(VERSION 3.10)
project(cIDE VERSION 0.1 DESCRIPTION "Console integrated development environment" HOMEPAGE_URL "" LANGUAGES C)

set(CMAKE_C_STANDARD 99)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
endif()


set(INCLUDES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/")
include_directories(${INCLUDES_DIR})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/settings.h.orig ${CMAKE_CURRENT_SOURCE_DIR}/include/settings.h COPYONLY)

add_subdirectory(src/)
