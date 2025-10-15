//
// Created by Beercan on 13/12/2021.
//

#include <optional>
#include <utility>
#include "RawBrick.h"
#include "Player.h"
#include "raymath.h"

Player::Player(const Texture2D& sprite, const Vector2& position, GameView gameView) :
    SpriteBrick(sprite, {9, 0, 3, 4}, position),
    gameView(std::move(gameView)),
    deathPosition(position)
{
}

void Player::handleDeath()
{
    // Mark the player as "dead"
    active = false;

    // Update the death scenes positions.
    for (int widthIndex = 0; widthIndex < deathSize; ++widthIndex)
    {
        for (int heightIndex = 0; heightIndex < deathSize; ++heightIndex)
        {
            deathZero[heightIndex][widthIndex].updatePosition(
                deathPosition
                + right * static_cast<float>(widthIndex)
                + down * static_cast<float>(heightIndex)
                + space
            );
            deathOne[heightIndex][widthIndex].updatePosition(
                deathPosition
                + right * static_cast<float>(widthIndex)
                + down * static_cast<float>(heightIndex)
                + space
            );
            deathTwo[heightIndex][widthIndex].updatePosition(
                deathPosition
                + right * static_cast<float>(widthIndex)
                + down * static_cast<float>(heightIndex)
                + space
            );
        }
    }
}

void Player::handleMovement(const float deltaTime)
{
    // Is it time to allow the next movement?
    if (active && (movementTime += deltaTime) < movementThreshold)
    {
        return;
    }

    // Reset tracker
    movementTime = 0.0f;

    // Update the death scene
    if ((deathTime += deltaTime) > deathThreshold)
    {
        if (++deathSceneIndex > 2) deathSceneIndex = 0;
        deathScene = deathSceneIndex == 0 ? deathZero : deathSceneIndex == 1 ? deathOne : deathTwo;
        deathTime = 0.0f;
    }

    // Stop moving, you're "dead"
    if (!active) return;

    // So are we moving?
    bool moveLeft{false};
    bool moveRight{false};
    //bool moveUp{false};
    //bool moveDown{false};

    // Detect Keyboard
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) moveLeft = true;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) moveRight = true;
    //if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) moveUp = true;
    //if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) moveDown = true;

#if defined(PLATFORM_ANDROID) || defined(EMULATE_ANDROID_UI)
    // Detect Touch
    if (IsGestureDetected(GESTURE_DRAG))
    {
        if (GetGestureDragVector().x < 0) moveLeft = true;
        if (GetGestureDragVector().x > 0) moveRight = true;
        //if (GetGestureDragVector().y < 0) moveUp = true;
        //if (GetGestureDragVector().y > 0) moveDown = true;
    }
#else
    // Detect Mouse
    if (GetMouseDelta().x < 0) moveLeft = true;
    if (GetMouseDelta().x > 0) moveRight = true;
    //if (GetMouseDelta().y < 0) moveUp = true;
    //if (GetMouseDelta().y > 0) moveDown = true;
#endif

    // Movement within game bounds
    if (moveRight && position.x + width < gameView.innerTopRight.x)
    {
        position += right;
        if (deathPosition.x + deathSize * scale * offset < gameView.innerTopRight.x)
        {
            deathPosition += right;
        }
    }
    if (moveLeft && position.x > gameView.innerTopLeft.x)
    {
        position += left;
        if (deathPosition.x > gameView.innerTopLeft.x)
        {
            deathPosition += left;
        }
    }
    //if (moveUp && position.y > gameView.innerTopLeft.y) {
    //    position += Brick::up;
    //    if (deathPosition.y > gameView.innerTopLeft.y) {
    //        deathPosition += Brick::up;
    //    }
    //}
    //if (moveDown && position.y + height < gameView.innerBottomLeft.y) {
    //    position += Brick::down;
    //    if (deathPosition.y + deathSize * scale * offset < gameView.innerBottomLeft.y) {
    //        deathPosition += Brick::down;
    //    }
    //}
}

std::optional<Bullet> Player::handleShooting(const float deltaTime)
{
    // Stop shooting, your "dead"
    if (!active) return std::nullopt;

    // Is it time to allow the next shot?
    if ((shootingTime += deltaTime) < shootingThreshold) return std::nullopt;

    // Check if a shot has been attempted
    if (!(IsKeyDown(KEY_SPACE) || IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsGestureDetected(GESTURE_TAP))) return std::nullopt;

    // Reset tracker
    shootingTime = 0.0f;

    // Spawn a bullet - two cells up and one to the right from the player
    Bullet bullet{
        position + space + up + right
    };

    return std::optional{bullet};
}

void Player::draw() const
{
    // Player is alive, draw as normal
    if (active) return SpriteBrick::draw();

    // Player is dead, so let's draw the death scene.
    for (const auto& row : deathScene)
    {
        for (const auto& brick : row)
        {
            if (brick.visible)
            {
                brick.draw();
            }
        }
    }
}
