//
// Created by Beercan on 13/12/2021.
//

#include <optional>
#include "RawBrick.h"
#include "Player.h"

Player::Player(const Texture2D &sprite, const Vector2 &position) :
    SpriteBrick(sprite, {9, 0, 3, 4}, position) {}

void Player::handleMovement(float deltaTime) {

    // Is it time to allow the next movement?
    if ((movementTime += deltaTime) < movementThreshold) {
        return;
    }

    // Reset tracker
    movementTime = 0.0f;

    // TODO - Handle world bounds, aka we shouldn't be able to move over the walls on the background.
    Vector2 position{this->position};
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) position = Vector2Add(position, Brick::right);
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) position = Vector2Add(position, Brick::left);
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) position = Vector2Add(position, Brick::up);
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) position = Vector2Add(position, Brick::down);
    updatePosition(position);
}

std::optional<Bullet> Player::handleShooting(float deltaTime) {

    // Is it time to allow the next movement?
    if ((shootingTime += deltaTime) < shootingThreshold) return std::nullopt;

    // Check if a shot has been attempted
    if (!IsKeyDown(KEY_SPACE)) return std::nullopt;

    // Reset tracker
    shootingTime = 0.0f;

    // Spawn a bullet - two cells up and one to the right from the player
    Bullet bullet{
        Vector2Add(
            position,
            Vector2Add(
                Vector2Scale(Brick::up, 2.0f),
                Brick::right
            )
        )
    };

    return std::optional{bullet};
}