cmake_minimum_required(VERSION 3.15)
project(CrossPlatformWindowAndUtility)


set(SOURCE_FILES
    src/platform.c
    src/main.c
)

add_executable(CrossPlatformWindowAndUtilityExample ${SOURCE_FILES} )


if(WIN32)
    set_target_properties(CrossPlatformWindowAndUtilityExample PROPERTIES
    LINK_FLAGS "/SUBSYSTEM:WINDOWS"
)
elseif(UNIX)
    find_package(X11 REQUIRED)
    target_link_libraries(CrossPlatformWindowAndUtilityExample X11 pthread m)
endif()