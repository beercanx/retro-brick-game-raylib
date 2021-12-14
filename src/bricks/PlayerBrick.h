//
// Created by Beercan on 13/12/2021.
//

#ifndef RETRO_BRICK_GAME_PLAYERBRICK_H
#define RETRO_BRICK_GAME_PLAYERBRICK_H

#include <optional>
#include "SpriteBrick.h"
#include "RawBrick.h"

class PlayerBrick : public SpriteBrick {

public:

    explicit PlayerBrick(const Texture2D &sprite, float rotation, const Vector2 &position);

    void handleMovement(float deltaTime);

    std::optional<RawBrick> handleShooting(float deltaTime);

private:

    const float movementThreshold{0.050f}; // 50ms
    float movementTime{};

    const float shootingThreshold{1.000f}; // 1s
    float shootingTime{};

};


#endif //RETRO_BRICK_GAME_PLAYERBRICK_H
