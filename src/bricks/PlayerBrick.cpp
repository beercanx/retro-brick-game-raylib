//
// Created by Beercan on 13/12/2021.
//

#include <optional>
#include "RawBrick.h"
#include "PlayerBrick.h"

PlayerBrick::PlayerBrick(const Texture2D &sprite, const float rotation, const Vector2 &position) :
    SpriteBrick(sprite, {9, 0, 3, 4}, rotation, position) {}

void PlayerBrick::handleMovement(float deltaTime) {

    // Is it time to allow the next movement?
    if ((movementTime += deltaTime) < movementThreshold) {
        return;
    }

    // Reset tracker
    movementTime = 0.0f;

    // TODO - Handle world bounds, aka we shouldn't be able to move over the walls on the background.
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) position = Vector2Add(position, Brick::right);
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) position = Vector2Add(position, Brick::left);
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) position = Vector2Add(position, Brick::up);
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) position = Vector2Add(position, Brick::down);

}

std::optional<RawBrick> PlayerBrick::handleShooting(float deltaTime) {

    // Is it time to allow the next movement?
    if ((shootingTime += deltaTime) < shootingThreshold) return std::nullopt;

    // Check if a shot has been attempted
    if (!IsKeyDown(KEY_SPACE)) return std::nullopt;

    // Reset tracker
    shootingTime = 0.0f;

    // Spawn a bullet
    RawBrick bullet{
        0.0f,
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