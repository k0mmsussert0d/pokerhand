cmake_minimum_required(VERSION 2.8)

project(pokerhand)
set(POKERHAND_CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(POKERHAND_CMAKE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR_DIR})

set(POKERHAND_CMAKE_VERSION_MAJOR 1)
set(POKERHAND_CMAKE_VERSION_MINOR 0)
set(POKERHAND_CMAKE_VERSION_PATCH 0)

set( POKERHAND_CMAKE_SOURCES
    main.c
    macro.c
    methods.c
    hand.c
)

set( POKERHAND_CMAKE_HEADERS
    hand.h
    macro.h
    methods.h
)

add_executable(${PROJECT_NAME} ${POKERHAND_CMAKE_SOURCES} ${POKERHAND_CMAKE_HEADERS} )

if ( "${CMAKE_C_COMPILER_ID}" STREQUAL "GNU" )
  add_definitions( --std=c11 )
endif()
