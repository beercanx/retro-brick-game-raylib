#include <iostream>
#include "raylib.h"
#include "bricks/SingleBrick.h"

int main() {

    std::cout << "Hello, World!" << std::endl;

    // Window Dimensions
    int windowWidth{800};
    int windowHeight{450};

    InitWindow(windowWidth, windowHeight, "Retro Brick Game");

    // New texture brick
    const Texture2D brickTexture{LoadTexture("assets/bricks/brick.png")};
    SingleBrick brick{
        brickTexture,
        2.0f,
        0.0f,
        {
            (float) windowWidth / 2.0f,
            (float) windowHeight / 2.0f
        }
    };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);

        // TODO - Draw a grid 1 brick (6 pixels) with 1 "pixel" wide gap, so draw the grid lines in the "gap".

        // TODO - Add a button to toggle the grid

        // TODO - Draw a game area box, that can contain 10 by 20 bricks.
        //        Left and right most bricks are a border.
        //        Game content moves in a 8 by 18 grid most of the time.

        // TODO - Draw the non game area:
        //          Score (title & value)
        //          Space to display if sound and music is enabled
        //          Space for Game Over text
        //          Space for a next shape view (Title + 4 by 4 grid)
        //          Space to display current speed (2 digits, maybe base speed)
        //          Space to display current level (2 digits)

        // TODO - Add non game buttons, starting with sound and music toggles

        // Draw brick
        brick.draw();

//        // Do X Axis Movement
//        if (IsKeyDown(KEY_D) && circleX + circleRadius < windowWidth) {
//            circleX += circleRadius;
//        }
//        if (IsKeyDown(KEY_A) && circleX - circleRadius > 0) {
//            circleX -= circleRadius;
//        }
//
//        // Do Y Axis Movement
//        if (IsKeyDown(KEY_W) && circleY - circleRadius > 0) {
//            circleY -= circleRadius;
//        }
//        if (IsKeyDown(KEY_S) && circleY + circleRadius < windowHeight) {
//            circleY += circleRadius;
//        }

        EndDrawing();
    }

    UnloadTexture(brickTexture);

    CloseWindow();

    return 0;
}
