#include <iostream>
#include <list>
#include "raylib.h"
#include "bricks/RawBrick.h"
#include "raymath.h"
#include "bricks/Enemy.h"
#include "bricks/Background.h"
#include "bricks/Player.h"
#include "bricks/Bullet.h"

int main() {

    std::cout << "Hello, World!" << std::endl;

    // Window Dimensions
    const int windowWidth{Brick::scale * 71};
    const int windowHeight{Brick::scale * 140};

    InitWindow(windowWidth, windowHeight, "Retro Brick Game");

    // Positions
    const Vector2 gameViewPosition{Brick::gap * Brick::scale, 0.0f};

    // Textures
    const Texture2D spriteTexture{LoadTexture("assets/bricks/sprite.png")};
    const Texture2D backgroundTexture{LoadTexture("assets/bricks/backgrounds.png")};

    // Bricks
    Background background{
        backgroundTexture,
        Background::START,
        gameViewPosition
    };
    Enemy enemy{
        spriteTexture,
        Enemy::Type::seat,
        90.0f,
        Vector2Add(
            gameViewPosition,
            Vector2Add(
                Vector2Scale(Brick::right, 4),
                Vector2Scale(Brick::down, 4)
            )
        )
    };
    Player player{
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

    // Bullets
    std::list<Bullet> bullets{};

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
        player.handleMovement(deltaTime);

        // TODO - Handle enemy movement

        // Handle bullet movement and collisions
        for(auto& bullet : bullets) {
            //bullet.tick(deltaTime);
            bullet.updatePosition(Vector2Add(bullet.position, Brick::up));
            // TODO - Handle collisions with enemies.
            // TODO - Remove bullet from game once invisible.
        }

        // Handler player shooting
        if(const auto& bullet = player.handleShooting(deltaTime)) {
            bullets.push_back(*bullet);
        }

        // Draw bricks
        background.draw();
        enemy.draw();
        player.draw();
        for(auto& bullet : bullets) {
            bullet.draw();
        }

        EndDrawing();
    }

    UnloadTexture(spriteTexture);
    UnloadTexture(backgroundTexture);

    CloseWindow();

    return 0;
}
