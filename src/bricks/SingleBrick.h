//
// Created by Beercan on 05/12/2021.
//

#ifndef RETRO_BRICK_GAME_SINGLEBRICK_H
#define RETRO_BRICK_GAME_SINGLEBRICK_H

#include "raylib.h"
#include "TextureBrick.h"

class SingleBrick : public TextureBrick {

public:

    SingleBrick(const Texture2D &texture, float scale, float rotation, const Vector2 &position);

    void draw() override;

};


#endif //RETRO_BRICK_GAME_SINGLEBRICK_H
