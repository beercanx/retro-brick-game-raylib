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

    virtual Rectangle getDestination();

protected:

    void updateSource(Rectangle value);

private:

    Rectangle source;
    float width;
    float height;

};

#endif //RETRO_BRICK_GAME_SPRITEBRICK_H
