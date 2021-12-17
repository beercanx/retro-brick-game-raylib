//
// Created by Beercan on 14/12/2021.
//

#ifndef RETRO_BRICK_GAME_BULLET_H
#define RETRO_BRICK_GAME_BULLET_H


#include "RawBrick.h"

class Bullet : public RawBrick {

public:

    explicit Bullet(const Vector2 &position);

    Rectangle getDestination();

};


#endif //RETRO_BRICK_GAME_BULLET_H
