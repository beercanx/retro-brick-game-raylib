#include <iostream>
#include <list>
#include <memory>
#include "raylib.h"
#include "raymath.h"
#include "bricks/RawBrick.h"
#include "bricks/Enemy.h"
#include "bricks/Player.h"
#include "bricks/Bullet.h"
#include "sidebar/Score.h"
#include "sidebar/GameOver.h"
#include "bricks/Background.h"
#include "sidebar/Level.h"
#include "GameView.h"
#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

// Game Area
Background background{Brick::space * 2};
const GameView gameView = background.gameView;

// Bricks
std::unique_ptr<Enemy> enemy;
std::unique_ptr<Player> player;

// Bullets
std::list<Bullet> bullets{};

// Sidebar
GameOver gameOver{gameView.innerTopLeft + Vector2{0, gameView.outer.height / 3}};
Score score{gameView.outerTopRight + Brick::right};
Level level{ gameView.outerTopRight + Brick::right + Brick::down};

// Pause
float pausedTrigger{0.0f};
#if defined(PLATFORM_ANDROID) || defined(EMULATE_ANDROID_UI)
bool paused{false};
#else
bool paused{true};
#endif

void UpdateDrawFrame();

int main() {

    TraceLog(LOG_INFO, "Starting Retro Brick Game");

    // Window Dimensions
#if defined(PLATFORM_ANDROID) || defined(EMULATE_ANDROID_UI)
    const int windowWidth{(int) gameView.border.width + Brick::offset};
    const int windowHeight{(int) gameView.border.height + Brick::offset};
#else
    // TODO - Consider changing to update based on GameView + Sidebar
    constexpr int windowWidth{Brick::scale * 149};
    constexpr int windowHeight{Brick::scale * 142 + static_cast<int>(Brick::space.y)};
#endif

    // Always on top
    SetConfigFlags(FLAG_WINDOW_TOPMOST);

    InitWindow(windowWidth, windowHeight, "Retro Brick Game");

    // Textures
    const Texture2D spriteTexture{LoadTexture(ASSETS_LOCATION"bricks/sprite.png")};

    // Bricks
    enemy = std::make_unique<Enemy>(
        spriteTexture,
        Enemy::Type::seat,
        gameView
    );
    player = std::make_unique<Player>(
        spriteTexture,
        gameView.innerTopLeft + (Brick::down * 13) + (Brick::right * 3) - Brick::space,
        gameView
    );

    // Register event hooks
    level.onLevelChange.emplace_back([&](int) -> void { background.resetBackground(); });
    level.onScoreScaleChange.emplace_back([&](const int scale) -> void { score.scoreScale = scale; });
    level.onSpeedScaleChange.emplace_back([&](const int scale) -> void { enemy->speedScale = scale; });
    level.onSpeedScaleChange.emplace_back([&](const int scale) -> void { background.speedScale = scale; });

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);
    while (!WindowShouldClose()) UpdateDrawFrame(); // Detect window close button or ESC key
#endif

    UnloadTexture(spriteTexture);

    CloseWindow();

    return 0;
}

void UpdateDrawFrame() {
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
        player->handleMovement(deltaTime);

        // Handle enemy movement
        enemy->handleMovement(deltaTime);

        // Handle enemy colliding with player
        if (CheckCollisionRecs(player->getDestination(), enemy->getDestination())) {
            TraceLog(LOG_INFO, "Player was killed by an Enemy");

            // Stop moving the background
            background.active = false;

            // Kill the player
            player->handleDeath();

            // Kill the enemy too?
            enemy->handleDeath();

            // Display game over
            gameOver.display();
        }

        // Handle bullet movement and collisions
        for (auto bullet = bullets.begin(); bullet != bullets.end(); ++bullet) {

            // Handle bullet movement
            bullet->updatePosition(bullet->position + Brick::up);

            // Handle collisions with enemies.
            if (CheckCollisionRecs(bullet->getDestination(), enemy->getDestination())) {
                TraceLog(LOG_INFO, "Bullet has collided with Enemy");
                level.updateProgress(1);
                score.increase();
                bullet = bullets.erase(bullet);
                enemy->handleReBirth();
                continue;
            }

            // Remove bullet from game once invisible.
            if (bullet->position.y < gameView.outerTopLeft.y) {
                TraceLog(LOG_INFO, "Bullet has been deleted");
                bullet = bullets.erase(bullet);
            }
        }

        // Handler player shooting
        if (const auto &bullet = player->handleShooting(deltaTime)) {
            bullets.push_back(*bullet);
        }
    }

    // Draw bricks
    background.draw();
    enemy->draw();
    player->draw();
    for(const auto& bullet : bullets) {
        bullet.draw();
    }

#if !defined(PLATFORM_ANDROID) && !defined(EMULATE_ANDROID_UI)
    // Draw Sidebar
    score.draw();
    level.draw();
#endif
    gameOver.draw();
    // TODO - Draw a level progress bar?
    // TODO - Draw next incoming shape
    if(paused) {
        DrawText(
            "Paused",
            static_cast<int>(gameView.inner.width) / 3,
            static_cast<int>(gameView.inner.height) / 3,
            10 * Brick::scale,
            RED
        );
    }

    // Gizmos
    //    DrawRectangleLinesEx(gameView.outer, 1.0f, RED);
    //    DrawLineV(gameView.outerTopLeft, gameView.outerTopRight, RED);
    //    DrawLineV(gameView.outerTopRight, gameView.outerBottomRight, RED);
    //    DrawLineV(gameView.outerBottomRight, gameView.outerBottomLeft, RED);
    //    DrawLineV(gameView.outerBottomLeft, gameView.outerTopLeft, RED);
    //
    //    DrawRectangleLinesEx(gameView.inner, 1.0f, PURPLE);
    //    DrawLineV(gameView.innerTopLeft, gameView.innerTopRight, PURPLE);
    //    DrawLineV(gameView.innerTopRight, gameView.innerBottomRight, PURPLE);
    //    DrawLineV(gameView.innerBottomRight, gameView.innerBottomLeft, PURPLE);
    //    DrawLineV(gameView.innerBottomLeft, gameView.innerTopLeft, PURPLE);

    EndDrawing();
}