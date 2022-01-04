cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(retro_brick_game LANGUAGES C CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##
# Setting parameters for raylib
##
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
set(OpenGL_GL_PREFERENCE GLVND)

##
# Dependencies
##
add_subdirectory(libs/raylib)

##
# Define the game
##
add_executable(${PROJECT_NAME} src/main.cpp
        src/bricks/Brick.cpp src/bricks/Brick.h
        src/bricks/RawBrick.cpp src/bricks/RawBrick.h
        src/bricks/TextureBrick.cpp src/bricks/TextureBrick.h
        src/bricks/SpriteBrick.cpp src/bricks/SpriteBrick.h
        src/bricks/Background.cpp src/bricks/Background.h
        src/bricks/Enemy.cpp src/bricks/Enemy.h
        src/bricks/Player.cpp src/bricks/Player.h
        src/bricks/Bullet.cpp src/bricks/Bullet.h
        src/sidebar/Score.cpp src/sidebar/Score.h
        )

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

enable_testing()

##
# Create distribution
##

# TODO - Create dist folder
# TODO - Copy in executable
# TODO - Copy in assets folder
# TODO - Externalise versioning

# TODO - Add Github Workflows
# TODO - Publish on a release
