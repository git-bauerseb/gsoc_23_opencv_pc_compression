cmake_minimum_required(VERSION 3.16)

project(gsoc_pc_compression)

set(SOURCES 
    main.cpp
)

add_executable(gsoc_pc_compression ${SOURCES})
target_link_libraries(gsoc_pc_compression ${OpenCV_LIBS})