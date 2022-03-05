//
// Created by Beercan on 13/12/2021.
//

#include <optional>
#include <array>
#include "RawBrick.h"
#include "Player.h"
#include "../raylib/Vector2.h"

Player::Player(const Texture2D &sprite, const Vector2 &position, const GameView gameView) :
    SpriteBrick(sprite, {9, 0, 3, 4}, position),
    gameView(gameView),
    deathPosition(position) {}

void Player::handleDeath() {

    // Mark player as "dead"
    active = false;

    // Update the death scenes positions.
    for (int widthIndex = 0; widthIndex < deathSize; ++widthIndex) {
        for (int heightIndex = 0; heightIndex < deathSize; ++heightIndex) {
            deathZero[heightIndex][widthIndex].updatePosition(
                deathPosition
                + (Brick::right * widthIndex)
                + (Brick::down * heightIndex)
                + Brick::space
            );
            deathOne[heightIndex][widthIndex].updatePosition(
                deathPosition
                + (Brick::right * widthIndex)
                + (Brick::down * heightIndex)
                + Brick::space
            );
            deathTwo[heightIndex][widthIndex].updatePosition(
                deathPosition
                + (Brick::right * widthIndex)
                + (Brick::down * heightIndex)
                + Brick::space
            );
        }
    }
}

void Player::handleMovement(const float deltaTime) {

    // Is it time to allow the next movement?
    if ((movementTime += deltaTime) < movementThreshold) {
        return;
    }

    // Reset tracker
    movementTime = 0.0f;

    // Update death scene
    if (++deathSceneIndex > 2) deathSceneIndex = 0;
    deathScene = deathSceneIndex == 0 ? deathZero : deathSceneIndex == 1 ? deathOne : deathTwo;

    // Stop moving, your "dead"
    if (!active) return;

    // Movement within game bounds
    if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && position.x + width < gameView.innerTopRight.x) {
        position += Brick::right;
        if (deathPosition.x + deathSize * scale * offset < gameView.innerTopRight.x) {
            deathPosition += Brick::right;
        }
    }
    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && position.x > gameView.innerTopLeft.x) {
        position += Brick::left;
        if (deathPosition.x > gameView.innerTopLeft.x) {
            deathPosition += Brick::left;
        }
    }
    //if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && position.y > gameView.innerTopLeft.y) {
    //    position += Brick::up;
    //    if (deathPosition.y > gameView.innerTopLeft.y) {
    //        deathPosition += Brick::up;
    //    }
    //}
    //if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && position.y + height < gameView.innerBottomLeft.y) {
    //    position += Brick::down;
    //    if (deathPosition.y + deathSize * scale * offset < gameView.innerBottomLeft.y) {
    //        deathPosition += Brick::down;
    //    }
    //}
}

std::optional<Bullet> Player::handleShooting(const float deltaTime) {

    // Stop shooting, your "dead"
    if (!active) return std::nullopt;

    // Is it time to allow the next movement?
    if ((shootingTime += deltaTime) < shootingThreshold) return std::nullopt;

    // Check if a shot has been attempted
    if (!IsKeyDown(KEY_SPACE)) return std::nullopt;

    // Reset tracker
    shootingTime = 0.0f;

    // Spawn a bullet - two cells up and one to the right from the player
    Bullet bullet{
        position + Brick::space + Brick::up + Brick::right
    };

    return std::optional{bullet};
}

void Player::draw() {

    // Player is alive, draw as normal
    if (active) return SpriteBrick::draw();

    // Player is dead, so lets draw the death scene.
    for (auto &row: deathScene) {
        for (auto &brick: row) {
            if (brick.visible) {
                brick.draw();
            }
        }
    }
}
