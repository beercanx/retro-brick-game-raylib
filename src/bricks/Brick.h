//
// Created by Beercan on 11/12/2021.
//

#ifndef RETRO_BRICK_GAME_BRICK_H
#define RETRO_BRICK_GAME_BRICK_H

#include "raylib.h"

class Brick {

public:

    explicit Brick(float scale, float rotation, const Vector2 &position);

    virtual void draw() = 0;

protected:

    const float scale;
    const float rotation;
    const Vector2 position;

};

#endif //RETRO_BRICK_GAME_BRICK_H
