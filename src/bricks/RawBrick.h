//
// Created by Beercan on 05/12/2021.
//

#ifndef RETRO_BRICK_GAME_RAWBRICK_H
#define RETRO_BRICK_GAME_RAWBRICK_H

#include "Brick.h"

class RawBrick : public Brick {

public:

    explicit RawBrick(float scale, float rotation, const Vector2 &position);

    void draw() override;

private:

    const Rectangle outerBorder;
    const Rectangle innerBorder;
    const Rectangle center;

};


#endif //RETRO_BRICK_GAME_RAWBRICK_H
