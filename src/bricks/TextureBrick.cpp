//
// Created by Beercan on 11/12/2021.
//

#include "TextureBrick.h"

TextureBrick::TextureBrick(
    const Texture2D &texture,
    const float rotation,
    const Vector2 &position
) : Brick(rotation, position),
    texture(texture) {}

void TextureBrick::draw() {
    DrawTextureEx(texture, position, rotation, scale, WHITE);
}