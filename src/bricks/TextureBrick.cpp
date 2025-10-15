//
// Created by Beercan on 11/12/2021.
//

#include "TextureBrick.h"

TextureBrick::TextureBrick(
    const Texture2D& texture,
    const Vector2& position
) : Brick(position),
    texture(texture)
{
}

void TextureBrick::draw() const
{
    DrawTextureEx(texture, position, 0.0f, scale, WHITE);
}
