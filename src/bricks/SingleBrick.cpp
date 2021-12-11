//
// Created by Beercan on 05/12/2021.
//

#include "SingleBrick.h"

SingleBrick::SingleBrick(const Texture2D &texture, const int windowWidth, const int windowHeight) :
    TextureBrick(texture),
    position({(float) windowWidth / 2.0f, (float) windowHeight / 2.0f}) {}

void SingleBrick::draw() {
    DrawTextureEx(texture, position, 0.0f, scale, WHITE);
}
