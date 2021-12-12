//
// Created by Beercan on 05/12/2021.
//

#include "SingleBrick.h"

SingleBrick::SingleBrick(const Texture2D &texture, const float rotation, const Vector2 &position) :
    TextureBrick(texture, rotation, position) {}

void SingleBrick::draw() {
    DrawTextureEx(texture, position, rotation, scale, WHITE);
}
