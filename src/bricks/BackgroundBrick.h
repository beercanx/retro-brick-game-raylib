//
// Created by Beercan on 13/12/2021.
//

#ifndef RETRO_BRICK_GAME_BACKGROUNDBRICK_H
#define RETRO_BRICK_GAME_BACKGROUNDBRICK_H

#include "raylib.h"
#include "SpriteBrick.h"

class BackgroundBrick : public SpriteBrick {

public:

    explicit BackgroundBrick(const Texture2D &sprite, const Rectangle &source, const Vector2 &position);

    constexpr static const Rectangle START{0, 0, 10, 20};
    constexpr static const Rectangle IN_PROGRESS{0, 0, 10, 20};

};


#endif //RETRO_BRICK_GAME_BACKGROUNDBRICK_H
