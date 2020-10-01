cmake_minimum_required(VERSION 2.8)

project(algo)

# add_subdirectory(lib)

include_directories(${PROJECT_SOURCE_DIR}/include)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

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