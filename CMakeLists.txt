cmake_minimum_required(VERSION 2.8)

project(algo)

include_directories("include")
set(SRC_LIST
    src/hello.c)

#add_library(libs 
#   )

add_executable(algo 
    src/main.c
    ${SRC_LIST})

#target_link_libraries(sayHello libHello)