//
// Created by Beercan on 13/12/2021.
//

#include <optional>
#include "RawBrick.h"
#include "Player.h"
#include "../raylib/Vector2.h"

Player::Player(const Texture2D &sprite, const Vector2 &position, const Rectangle &gameView) :
    SpriteBrick(sprite, {9, 0, 3, 4}, position),
    topLeft({gameView.x + right.x, gameView.y}),
    topRight({gameView.x + gameView.width + left.x - gap * scale, gameView.y}),
    bottomLeft({topLeft.x, gameView.y + gameView.height - gap * scale}),
    bottomRight({topRight.x, bottomLeft.y}) {}

void Player::handleDeath() {
    active = false;
}

void Player::handleMovement(const float deltaTime) {

    // Stop moving, your "dead"
    if (!active) return;

    // Is it time to allow the next movement?
    if ((movementTime += deltaTime) < movementThreshold) {
        return;
    }

    // Reset tracker
    movementTime = 0.0f;

    // Movement within game bounds
    const Rectangle destination = getDestination();
    if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && destination.x + destination.width < topRight.x) {
        position += Brick::right;
    }
    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && destination.x > topLeft.x) {
        position += Brick::left;
    }
    //if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && destination.y > topLeft.y){
    //    position += Brick::up;
    //}
    //if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && destination.y + destination.height < bottomLeft.y) {
    //    position += Brick::down;
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
        position + (Brick::up * 2.0f) + Brick::right
    };

    return std::optional{bullet};
}
