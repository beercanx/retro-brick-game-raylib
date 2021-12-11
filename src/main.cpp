#include <iostream>
#include "raylib.h"
#include "bricks/TextureBrick.h"

int main() {

    std::cout << "Hello, World!" << std::endl;

    // Window Dimensions
    int windowWidth{800};
    int windowHeight{450};

    InitWindow(windowWidth, windowHeight, "Retro Brick Game");

    // New
    TextureBrick brick = TextureBrick(windowWidth, windowHeight);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);

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

    brick.unloadTextures();

    CloseWindow();

    return 0;
}
