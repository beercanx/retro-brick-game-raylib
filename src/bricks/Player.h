//
// Created by Beercan on 13/12/2021.
//

#ifndef RETRO_BRICK_GAME_PLAYER_H
#define RETRO_BRICK_GAME_PLAYER_H

#include <optional>
#include "SpriteBrick.h"
#include "RawBrick.h"
#include "Bullet.h"
#include "../GameView.h"

class Player : public SpriteBrick {

public:

    explicit Player(const Texture2D &sprite, const Vector2 &position, GameView gameView);

    void handleDeath();

    void handleMovement(float deltaTime);

    std::optional<Bullet> handleShooting(float deltaTime);

private:

    bool active{true};

    const float movementThreshold{0.050f}; // 50ms
    float movementTime{};

    const float shootingThreshold{0.250f}; // 250ms
    float shootingTime{};

    // Game boundaries
    const GameView gameView;
};


#endif //RETRO_BRICK_GAME_PLAYER_H
