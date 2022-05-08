cmake_minimum_required(VERSION 3.0)

project(algo)
set(CMAKE_C_FLAGS "-g")

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fno-omit-frame-pointer")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer ")

set (CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address  -lasan -lstdc++ ")

set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address  -lasan -lstdc++ ")

########################config env#########################

set(CMAKE_BUILD_TYPE Debug)

IF (${LIBSRC} STREQUAL "fib")
    add_definitions(-D OPTION_FIB)
ENDIF (${LIBSRC} STREQUAL "fib")

IF (${LONGBIT} STREQUAL "64")
    add_definitions(-D SYS_LONG_BIT_64)
    MESSAGE("[warn]system 64")
ELSEIF (${LONGBIT} STREQUAL "32")
    add_definitions(-D SYS_LONG_BIT_32)
    MESSAGE("[warn]system 32")
ENDIF (${LONGBIT} STREQUAL "64")


include_directories(
    ${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/lib)

#link_libraries(libalgointerface.a)

add_subdirectory(${PROJECT_SOURCE_DIR}/lib)


set(SRC_LIST
    src/hello.c
    src/measure.c
    src/multi_thread_demo.c
)

add_executable(algo 
    src/main.c
    ${SRC_LIST}
)

#add lib
target_link_libraries(algo 
    algointerface
    pthread
    asan)

