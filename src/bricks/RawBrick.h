//
// Created by Beercan on 05/12/2021.
//

#ifndef RETRO_BRICK_GAME_RAWBRICK_H
#define RETRO_BRICK_GAME_RAWBRICK_H

#include "Brick.h"

class RawBrick : public Brick
{
public:
    bool visible{true};

    virtual ~RawBrick() = default;

    RawBrick(bool visible);

    explicit RawBrick(const Vector2& position);

    void draw() const override;

    void updatePosition(const Vector2& position);

protected:
    Rectangle outerBorder{};
    Rectangle innerBorder{};
    Rectangle center{};
};


#endif //RETRO_BRICK_GAME_RAWBRICK_H
