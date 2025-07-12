//
// Created by Beercan on 14/12/2021.
//

#ifndef RETRO_BRICK_GAME_BULLET_H
#define RETRO_BRICK_GAME_BULLET_H

#include "RawBrick.h"

class Bullet final : public RawBrick {

public:

    explicit Bullet(const Vector2 &position);

    [[nodiscard]] Rectangle getDestination() const;

};

#endif //RETRO_BRICK_GAME_BULLET_H
