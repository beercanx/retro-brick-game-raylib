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
#include "GameView.h"

int main() {

    std::cout << "Starting Retro Brick Game" << std::endl;

    // Window Dimensions
    const int windowWidth{Brick::scale * 149};
    const int windowHeight{Brick::scale * 142 + (int) Brick::space.y};

    // Always on top
    SetConfigFlags(FLAG_WINDOW_TOPMOST);

    InitWindow(windowWidth, windowHeight, "Retro Brick Game");

    // Textures
    const Texture2D spriteTexture{LoadTexture("assets/bricks/sprite.png")};

    // Game Area
    Background background{Brick::space * 2};
    const GameView gameView = background.gameView;

    // Bricks
    Enemy enemy{
        spriteTexture,
        Enemy::Type::seat,
        gameView
    };
    Player player{
        spriteTexture,
        gameView.innerTopLeft + (Brick::down * 13) + (Brick::right * 3) - Brick::space,
        gameView
    };

    // Bullets
    std::list<Bullet> bullets{};

    // Sidebar
    Score score{gameView.outerTopRight + Brick::right};
    Level level{ gameView.outerTopRight + Brick::right + Brick::down};
    GameOver gameOver{gameView.innerTopLeft + Vector2{0, gameView.outer.height / 3}};

    // Register event hooks
    level.onLevelChange.emplace_back([&background](int) -> void { background.resetBackground(); });
    level.onScoreScaleChange.emplace_back([&score](int scale) -> void { score.scoreScale = scale; });
    level.onSpeedScaleChange.emplace_back([&enemy](int scale) -> void { enemy.speedScale = scale; });
    level.onSpeedScaleChange.emplace_back([&background](int scale) -> void { background.speedScale = scale; });

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
        //          Score -- DONE
        //          Level -- DONE
        //          Music -- Space to display if sound and music is enabled
        //          Game Over -- Space for Game Over text
        //          Next -- Text
        //          Next Shape - Space for a next shape view (Title + 4 by 4 grid)
        //          Speed -- Text
        //          Speed -- Space to display current speed (2 digits, maybe base speed)
        //          Level -- Text
        //          Level -- Space to display current level (2 digits)
        //          Paused -- Space to display a pause symbol (maybe a cup tea/coffee)

        // TODO - Add non game buttons, starting with a pause, sound and music toggles

        if(!paused) {

            background.handleMovement(deltaTime);

            // Handle player movement
            player.handleMovement(deltaTime);

            // Handle enemy movement
            enemy.handleMovement(deltaTime);

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
                    score.increase();
                    bullets.erase(bullet);
                    enemy.handleReBirth();
                }

                // Remove bullet from game once invisible.
                if (bullet->position.y < gameView.outerTopLeft.y) {
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
        for(const auto& bullet : bullets) {
            bullet.draw();
        }

        // Draw Sidebar
        score.draw();
        level.draw();
        gameOver.draw();
        // TODO - Draw a level progress bar?
        // TODO - Draw next incoming shape
        if(paused) {
            DrawText(
                "Paused",
                (int) gameView.inner.width / 3,
                (int) gameView.inner.height / 3,
                10 * Brick::scale,
                RED
            );
        }

        // Gizmos
//        DrawRectangleLinesEx(gameView.outer, 1.0f, RED);
//        DrawLineV(gameView.outerTopLeft, gameView.outerTopRight, RED);
//        DrawLineV(gameView.outerTopRight, gameView.outerBottomRight, RED);
//        DrawLineV(gameView.outerBottomRight, gameView.outerBottomLeft, RED);
//        DrawLineV(gameView.outerBottomLeft, gameView.outerTopLeft, RED);

//        DrawRectangleLinesEx(gameView.inner, 1.0f, PURPLE);
//        DrawLineV(gameView.innerTopLeft, gameView.innerTopRight, PURPLE);
//        DrawLineV(gameView.innerTopRight, gameView.innerBottomRight, PURPLE);
//        DrawLineV(gameView.innerBottomRight, gameView.innerBottomLeft, PURPLE);
//        DrawLineV(gameView.innerBottomLeft, gameView.innerTopLeft, PURPLE);

        EndDrawing();
    }

    UnloadTexture(spriteTexture);

    CloseWindow();

    return 0;
}
