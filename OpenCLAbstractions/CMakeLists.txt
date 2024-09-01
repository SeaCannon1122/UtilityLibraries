cmake_minimum_required(VERSION 3.15)
project(OpenCLAbstractions)


set(SOURCE_FILES
    src/main.c
    src/parallel_computing.c
)

include_directories(${PROJECT_SOURCE_DIR}/dependencies/OpenCL/inc)
link_directories(${PROJECT_SOURCE_DIR}/dependencies/OpenCL/lib/x64)

add_executable(OpenCLAbstractionsExample ${SOURCE_FILES} )

target_link_libraries(OpenCLAbstractionsExample OpenCL)