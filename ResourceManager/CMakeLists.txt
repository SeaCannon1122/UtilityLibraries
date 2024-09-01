cmake_minimum_required(VERSION 3.15)
project(ResourceManager)

set(SOURCE_FILES
    src/main.c
    src/resource_manager.c
)

include_directories(${PROJECT_SOURCE_DIR}/dependencies/stb_image)

add_executable(ResourceManagerExample ${SOURCE_FILES} )

set(RESOURCE_DIRECTORY "${CMAKE_SOURCE_DIR}/resources")
set(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_custom_command(TARGET ResourceManagerExample POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${RESOURCE_DIRECTORY}"
    "${OUTPUT_DIRECTORY}"
    COMMENT "Copying resources from ${RESOURCE_DIRECTORY} to ${OUTPUT_DIRECTORY}"
)