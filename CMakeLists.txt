cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(retro_brick_game LANGUAGES CXX VERSION 0.0.3)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##
# Dependencies
##
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    # Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24:
    if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
        cmake_policy(SET CMP0135 NEW)
    endif ()
    FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif ()
endif ()

##
# Define the game
##
file(GLOB_RECURSE PROJECT_SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

if (${PLATFORM} STREQUAL "Android")
    # Define the output as a library
    add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_FILES})
else ()
    # Define the output as an executable
    add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})
endif ()

target_link_libraries(${PROJECT_NAME} raylib)

##
# Android Configurations
##
if (${PLATFORM} STREQUAL "Android")
    # Declare a link on the Native Activity onCreate
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")
endif ()

##
# Web Configurations - https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5)
##
if (${PLATFORM} STREQUAL "Web")

    # Tell the linker that the game/library uses GLFW3 library internally
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3")

    # Specify a resources directory for data compilation
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file ${CMAKE_SOURCE_DIR}/assets@assets")

    # Enable runtime checks for common memory allocation errors
    #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s ASSERTIONS=1")

    # Force filesystem creation to load/save files data
    #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s FORCE_FILESYSTEM=1")

    # Replace default emscripten shell with Raylib one
    #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --shell-file ${raylib_SOURCE_DIR}/src/shell.html")
    #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --shell-file ${raylib_SOURCE_DIR}/src/minshell.html")

    # Replace default emscripten shell with our own forked from the Raylib one
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --shell-file ${CMAKE_SOURCE_DIR}/src/shell.html")

    # Specify a heap memory size in bytes (default = 16MB) (67108864 = 64MB)
    #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s TOTAL_MEMORY=67108864")

    # Tell Emscripten to build an example.html file.
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif ()

##
# Create distribution
##

# TODO - Create dist folder
# TODO - Copy in executable
# TODO - Copy in assets folder
# TODO - Externalise versioning

# TODO - Add Github Workflows
# TODO - Publish on a release
