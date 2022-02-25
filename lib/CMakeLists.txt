cmake_minimum_required(VERSION 2.8)

MESSAGE(">>add algLib:")
MESSAGE(${LIBSRC} ";" ${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include)

SET(src_SRC
    alolog.c
)

IF (${LIBSRC} STREQUAL "fib")
SET(algo_SRCS
    fib.c
    ${src_SRC}
)
ENDIF (${LIBSRC} STREQUAL "fib")


add_library(algointerface STATIC ${algo_SRCS})

MESSAGE("<< add algLib finish: ${algo_SRCS}")