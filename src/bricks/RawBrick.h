//
// Created by Beercan on 05/12/2021.
//

#ifndef RETRO_BRICK_GAME_RAWBRICK_H
#define RETRO_BRICK_GAME_RAWBRICK_H

#include "Brick.h"

class RawBrick : public Brick {

public:

    RawBrick() : Brick(0, 0, Vector2()) {}

    void draw() override;

};


#endif //RETRO_BRICK_GAME_RAWBRICK_H
