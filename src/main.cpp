#include <iostream>
#include "raylib.h"

int main() {

    std::cout << "Hello, World!" << std::endl;

    // Window Dimensions
    int windowWidth{800};
    int windowHeight{450};

    InitWindow(windowWidth, windowHeight, "Retro Brick Game");

    // Circle
    int circleX{windowWidth / 2};
    int circleY{windowHeight / 2};
    int circleRadius{25};

    // Axe
    int axeX{300};
    int axeY{0};
    int axeWidth{50};
    int axeHeight{50};
    int axeDirection{10};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);

        // Draw Circle
        DrawCircle(circleX, circleY, (float) circleRadius, BLUE);

        // Draw Axe
        DrawRectangle(axeX, axeY, axeWidth, axeHeight, RED);

        // Move the Axe
        axeY += axeDirection;
        if (axeY + axeHeight > windowHeight || axeY < 0) {
            axeDirection = -axeDirection;
        }

        // Do X Axis Movement
        if (IsKeyDown(KEY_D) && circleX + circleRadius < windowWidth) {
            circleX += circleRadius;
        }
        if (IsKeyDown(KEY_A) && circleX - circleRadius > 0) {
            circleX -= circleRadius;
        }

        // Do Y Axis Movement
        if (IsKeyDown(KEY_W) && circleY - circleRadius > 0) {
            circleY -= circleRadius;
        }
        if (IsKeyDown(KEY_S) && circleY + circleRadius < windowHeight) {
            circleY += circleRadius;
        }

        EndDrawing();
    }

    return 0;
}
