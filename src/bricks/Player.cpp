//
// Created by Beercan on 13/12/2021.
//

#include <optional>
#include "RawBrick.h"
#include "Player.h"
#include "../raylib/Vector2.h"

Player::Player(const Texture2D &sprite, const Vector2 &position, const GameView gameView) :
    SpriteBrick(sprite, {9, 0, 3, 4}, position),
    gameView(gameView) {}

void Player::handleDeath() {
    active = false;
    // TODO - Trigger death scene.
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
    if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && position.x + width < gameView.innerTopRight.x) {
        position += Brick::right;
    }
    if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && position.x > gameView.innerTopLeft.x) {
        position += Brick::left;
    }
    //if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && position.y > gameView.innerTopLeft.y){
    //    position += Brick::up;
    //}
    //if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && position.y + height < gameView.innerBottomLeft.y) {
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
        position + Brick::space + Brick::up + Brick::right
    };

    return std::optional{bullet};
}
