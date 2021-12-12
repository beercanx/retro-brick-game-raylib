//
// Created by Beercan on 11/12/2021.
//

#ifndef RETRO_BRICK_GAME_TEXTUREBRICK_H
#define RETRO_BRICK_GAME_TEXTUREBRICK_H

#include "raylib.h"
#include "Brick.h"

class TextureBrick : public Brick {

public:

    explicit TextureBrick(const Texture2D &texture, float scale, float rotation, const Vector2 &position);

protected:

    const Texture2D texture;

};

#endif //RETRO_BRICK_GAME_TEXTUREBRICK_H
