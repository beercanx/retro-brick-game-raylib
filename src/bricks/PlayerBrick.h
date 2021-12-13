//
// Created by Beercan on 13/12/2021.
//

#ifndef RETRO_BRICK_GAME_PLAYERBRICK_H
#define RETRO_BRICK_GAME_PLAYERBRICK_H

#include "SpriteBrick.h"

class PlayerBrick : public SpriteBrick {

public:

    explicit PlayerBrick(const Texture2D &sprite, float rotation, const Vector2 &position);

    void handleMovement(float deltaTime);

private:

    const float updateTime{0.075f}; // 75ms
    float runningTime{};
};


#endif //RETRO_BRICK_GAME_PLAYERBRICK_H
