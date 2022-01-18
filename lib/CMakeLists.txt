cmake_minimum_required(VERSION 2.8)

MESSAGE(">>add algLib:")
MESSAGE(${LIBSRC} ${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include)

IF (${LIBSRC} STREQUAL "fib")
SET(algo_SRCS
    fib.c
)
ENDIF (${LIBSRC} STREQUAL "fib")

ADD_LIBRARY(algointerface ${algo_SRCS})