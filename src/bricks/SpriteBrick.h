//
// Created by Beercan on 12/12/2021.
//

#ifndef RETRO_BRICK_GAME_SPRITEBRICK_H
#define RETRO_BRICK_GAME_SPRITEBRICK_H

#include "raylib.h"
#include "TextureBrick.h"

class SpriteBrick : public TextureBrick {

public:

    explicit SpriteBrick(const Texture2D &sprite, Rectangle source, const Vector2 &position);

    void draw() override;

    void updatePosition(const Vector2 &position);

    Rectangle getDestination();

private:

    const Rectangle source;
    Rectangle destination;

};

#endif //RETRO_BRICK_GAME_SPRITEBRICK_H
