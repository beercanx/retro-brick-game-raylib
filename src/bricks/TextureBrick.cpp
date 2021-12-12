//
// Created by Beercan on 11/12/2021.
//

#include "TextureBrick.h"

TextureBrick::TextureBrick(
    const Texture2D &texture,
    const float scale,
    const float rotation,
    const Vector2 &position
) : Brick(scale, rotation, position),
    texture(texture) {}
