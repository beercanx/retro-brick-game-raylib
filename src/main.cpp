#include <iostream>
#include <list>
#include "raylib.h"
#include "bricks/RawBrick.h"
#include "raymath.h"
#include "bricks/Enemy.h"
#include "bricks/Background.h"
#include "bricks/Player.h"
#include "bricks/Bullet.h"
#include "sidebar/Score.h"

int main() {

    std::cout << "Starting Retro Brick Game" << std::endl;

    // Window Dimensions
    const int windowWidth{Brick::scale * 149};
    const int windowHeight{Brick::scale * 141};

    // Always on top
    SetConfigFlags(FLAG_WINDOW_TOPMOST);

    InitWindow(windowWidth, windowHeight, "Retro Brick Game");

    // Positions
    const Vector2 gameViewPosition{1.0f, 1.0f};

    // Textures
    const Texture2D spriteTexture{LoadTexture("assets/bricks/sprite.png")};
    const Texture2D backgroundTexture{LoadTexture("assets/bricks/backgrounds.png")};

    // Game Area
    Background background{
        backgroundTexture,
        Background::START,
        gameViewPosition
    };

    const Rectangle gameView = background.getDestination();

    // Bricks
    Enemy enemy{
        spriteTexture,
        Enemy::Type::seat,
        Vector2Add( // TODO - Support random position placement
            gameViewPosition,
            Vector2Scale(Brick::right, 4)
        )
    };
    Player player{
        spriteTexture,
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

    // Sidebar
    Score score{{gameView.width + Brick::right.x,0}};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        const float deltaTime = GetFrameTime();

        BeginDrawing();
        ClearBackground(WHITE);

        // TODO - Draw the non game area:
        //          Score (title & value)
        //          Space to display if sound and music is enabled
        //          Space for Game Over text
        //          Space for a next shape view (Title + 4 by 4 grid)
        //          Space to display current speed (2 digits, maybe base speed)
        //          Space to display current level (2 digits)
        //          Space to display a pause symbol (maybe a cup tea/coffee)

        // TODO - Add non game buttons, starting with a pause, sound and music toggles

        // TODO - Draw more backgrounds to emphasise the game progression by switching to in_progress.

        // Handle player movement
        player.handleMovement(deltaTime);

        // Handle enemy movement
        enemy.handleMovement(deltaTime);

        // Handle bullet movement and collisions
        for (auto bullet = bullets.begin(); bullet!=bullets.end(); bullet++){

            // Handle bullet movement
            bullet->updatePosition(Vector2Add(bullet->position, Brick::up));

            // Handle collisions with enemies.
            if(CheckCollisionRecs(bullet->getDestination(), enemy.getDestination())) {
                std::cout << "Bullet has collided with Enemy" << std::endl;
                score.increase(1); // TODO - Scale on difficulty
                bullets.erase(bullet);
                enemy.handleDeath();
            }

            // Remove bullet from game once invisible.
            if(bullet->position.y < gameViewPosition.y) {
                std::cout << "Bullet has been deleted" << std::endl;
                bullets.erase(bullet);
            }
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

        // Draw Sidebar
        score.draw();

        EndDrawing();
    }

    UnloadTexture(spriteTexture);
    UnloadTexture(backgroundTexture);

    CloseWindow();

    return 0;
}
