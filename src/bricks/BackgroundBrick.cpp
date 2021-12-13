//
// Created by Beercan on 13/12/2021.
//

#include "BackgroundBrick.h"

BackgroundBrick::BackgroundBrick(const Texture2D &sprite, const Rectangle &source, const Vector2 &position) :
    SpriteBrick(sprite, source, 0.0f, position) {}
