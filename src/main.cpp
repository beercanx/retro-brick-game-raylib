#include <iostream>
#include <list>
#include "raylib.h"
#include "bricks/RawBrick.h"
#include "bricks/Enemy.h"
#include "bricks/Player.h"
#include "bricks/Bullet.h"
#include "sidebar/Score.h"
#include "sidebar/GameOver.h"
#include "bricks/Background.h"
#include "raylib/Vector2.h"
#include "sidebar/Level.h"

int main() {

    std::cout << "Starting Retro Brick Game" << std::endl;

    // Window Dimensions
    const int windowWidth{Brick::scale * 149};
    const int windowHeight{Brick::scale * 141};

    // Always on top
    SetConfigFlags(FLAG_WINDOW_TOPMOST);

    InitWindow(windowWidth, windowHeight, "Retro Brick Game");

    // Positions
    const Vector2 gameViewPosition{1.0f * Brick::scale, 1.0f * Brick::scale};

    // Textures
    const Texture2D spriteTexture{LoadTexture("assets/bricks/sprite.png")};
    const Texture2D backgroundTexture{LoadTexture("assets/bricks/backgrounds.png")};

    // Game Area
    Background background{gameViewPosition};

    const Rectangle gameView = background.getGameView();

    // Bricks
    Enemy enemy{
        spriteTexture,
        Enemy::Type::seat,
        gameViewPosition + (Brick::right * 4) - Brick::space // TODO - Support random position placement
    };
    Player player{
        spriteTexture,
        gameViewPosition + (Brick::down * 13) + (Brick::right * 4) - Brick::space,
        gameView
    };

    // Bullets
    std::list<Bullet> bullets{};

    // Sidebar
    Score score{{gameView.width + Brick::right.x, 0}};
    Level level{{gameView.width + Brick::right.x, Brick::down.y}};
    GameOver gameOver{{Brick::right.x + Brick::gap * Brick::scale, gameView.height / 3}};

    // Pause
    float pausedTrigger{0.0f};
    bool paused{true};

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        const float deltaTime = GetFrameTime();

        BeginDrawing();
        ClearBackground(WHITE);

        pausedTrigger += deltaTime;
        if(IsKeyDown(KEY_P) && pausedTrigger >= 0.1f) {
            paused = !paused;
            pausedTrigger = 0.0f;
        }

        // TODO - Draw the non game area:
        //          Space to display if sound and music is enabled
        //          Space for Game Over text
        //          Space for a next shape view (Title + 4 by 4 grid)
        //          Space to display current speed (2 digits, maybe base speed)
        //          Space to display current level (2 digits)
        //          Space to display a pause symbol (maybe a cup tea/coffee)

        // TODO - Add non game buttons, starting with a pause, sound and music toggles

        if(!paused) {

            background.handleMovement(deltaTime);

            // Handle player movement
            player.handleMovement(deltaTime);

            // Handle enemy movement
            enemy.handleMovement(deltaTime * level.getSpeedScale());

            // Handle enemy colliding with player
            if (CheckCollisionRecs(player.getDestination(), enemy.getDestination())) {
                std::cout << "Player was killed by an Enemy" << std::endl;

                // Stop moving the background
                background.active = false;

                // Kill the player
                player.handleDeath();

                // Kill the enemy too?
                enemy.handleDeath();

                // Display game over
                gameOver.display();
            }

            // Handle bullet movement and collisions
            for (auto bullet = bullets.begin(); bullet != bullets.end(); bullet++) {

                // Handle bullet movement
                bullet->updatePosition(bullet->position + Brick::up);

                // Handle collisions with enemies.
                if (CheckCollisionRecs(bullet->getDestination(), enemy.getDestination())) {
                    std::cout << "Bullet has collided with Enemy" << std::endl;
                    level.updateProgress(1);
                    score.increase(1 * level.getScoreScale());
                    bullets.erase(bullet);
                    enemy.handleReBirth();
                }

                // Remove bullet from game once invisible.
                if (bullet->position.y < gameViewPosition.y) {
                    std::cout << "Bullet has been deleted" << std::endl;
                    bullets.erase(bullet);
                }
            }

            // Handler player shooting
            if (const auto &bullet = player.handleShooting(deltaTime)) {
                bullets.push_back(*bullet);
            }
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
        level.draw();
        gameOver.draw();
        if(paused) {
            DrawText(
                "Paused",
                Brick::right.x + (Brick::gap * Brick::scale) * 10,
                (int) gameView.height / 3,
                10 * Brick::scale,
                RED
            );
        }

        EndDrawing();
    }

    UnloadTexture(spriteTexture);
    UnloadTexture(backgroundTexture);

    CloseWindow();

    return 0;
}
