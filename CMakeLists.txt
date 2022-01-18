cmake_minimum_required(VERSION 3.0)

project(algo)

set(CMAKE_BUILD_TYPE Debug)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(lib)

LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

IF (${LIBSRC} STREQUAL "fib")
    add_definitions(-D OPTION_FIB)
ENDIF (${LIBSRC} STREQUAL "fib")


set(SRC_LIST
    src/hello.c
    src/measure.c
)

add_executable(algo 
    src/main.c
    ${SRC_LIST}
)

#add lib
TARGET_LINK_LIBRARIES(algo libalgointerface.a)