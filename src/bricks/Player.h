//
// Created by Beercan on 13/12/2021.
//

#ifndef RETRO_BRICK_GAME_PLAYER_H
#define RETRO_BRICK_GAME_PLAYER_H

#include <optional>
#include "SpriteBrick.h"
#include "RawBrick.h"
#include "Bullet.h"

class Player : public SpriteBrick {

public:

    explicit Player(const Texture2D &sprite, float rotation, const Vector2 &position);

    void handleMovement(float deltaTime);

    std::optional<Bullet> handleShooting(float deltaTime);

private:

    const float movementThreshold{0.050f}; // 50ms
    float movementTime{};

    const float shootingThreshold{0.250f}; // 250ms
    float shootingTime{};

};


#endif //RETRO_BRICK_GAME_PLAYER_H
