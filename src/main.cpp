#include <iostream>
#include "raylib.h"
#include "bricks/RawBrick.h"
#include "raymath.h"
#include "bricks/SpriteBrick.h"
#include "bricks/EnemyBrick.h"
#include "bricks/BackgroundBrick.h"
#include "bricks/PlayerBrick.h"

int main() {

    std::cout << "Hello, World!" << std::endl;

    // Window Dimensions
    const int windowWidth{Brick::scale * 100};
    const int windowHeight{Brick::scale * 200};

    InitWindow(windowWidth, windowHeight, "Retro Brick Game");

    // Positions
    const Vector2 gameViewPosition{Brick::gap * Brick::scale, 0.0f};

    // Textures
    const Texture2D spriteTexture{LoadTexture("assets/bricks/sprite.png")};
    const Texture2D backgroundTexture{LoadTexture("assets/bricks/backgrounds.png")};

    // Bricks
    BackgroundBrick backgroundBrick{
        backgroundTexture,
        BackgroundBrick::START,
        gameViewPosition
    };
    EnemyBrick enemyBrick{
        spriteTexture,
        EnemyBrick::Type::seat,
        90.0f,
        Vector2Add(
            gameViewPosition,
            Vector2Add(
                Vector2Scale(Brick::right, 4),
                Vector2Scale(Brick::down, 4)
            )
        )
    };
    PlayerBrick playerBrick{
        spriteTexture,
        0.0f,
        Vector2Add(
            gameViewPosition,
            Vector2Add(
                Vector2Scale(Brick::down, 13),
                Vector2Scale(Brick::right, 4)
            )
        )
    };
    RawBrick bulletOne{
        0.0f,
        Vector2Add(
            playerBrick.position,
            Vector2Add(
                Vector2Scale(Brick::up, 2),
                Vector2Scale(Brick::right, 1)
            )
        )
    };
    RawBrick bulletTwo{
        0.0f,
        Vector2Add(
            bulletOne.position,
            Vector2Scale(Brick::up, 2)
        )
    };

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        const float deltaTime = GetFrameTime();

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
        //          Space to display a pause symbol (maybe a cup tea/coffee)

        // TODO - Add non game buttons, starting with a pause, sound and music toggles

        // Handle player movement
        playerBrick.handleMovement(deltaTime);

        // Draw bricks
        backgroundBrick.draw();
        bulletOne.draw();
        bulletTwo.draw();
        enemyBrick.draw();
        playerBrick.draw();

        EndDrawing();
    }

    UnloadTexture(spriteTexture);
    UnloadTexture(backgroundTexture);

    CloseWindow();

    return 0;
}
