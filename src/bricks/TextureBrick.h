//
// Created by Beer on 05/12/2021.
//

#ifndef RETRO_BRICK_GAME_TEXTUREBRICK_H
#define RETRO_BRICK_GAME_TEXTUREBRICK_H

#include "raylib.h"

class TextureBrick {

public:

    TextureBrick(int windowWidth, int windowHeight);

    void draw();

    void unloadTextures();

private:

    const int bricks{1};
    const float scale{2.0f};

    const Texture2D brick{LoadTexture("assets/bricks/brick.png")};
    const Rectangle source{(float) brick.width, 0.0f, (float) brick.width, (float) brick.height};

    const Vector2 position;
    const Rectangle destination;

    /**
     * tee 3 by 3
     * ###
     *  #
     *  #
     *
     * line 1 by 4
     *  #
     *  #
     *  #
     *  #
     *
     * pyramid 3 by 2
     *  #
     * ###
     *
     * square 2 by 2
     *  ##
     *  ##
     *
     * seat 3 by 2
     * # #
     * ###
     *
     * zee 3 by 3
     * ##
     *  #
     *  ##
     *
     * zee inverse 3 by 3
     *  ##
     *  #
     * ##
     *
     * step 2 by 2
     *  #
     *  ##
     *
     * ell 2 by 3
     *  #
     *  #
     *  ##
     *
     * ell inverse 2 by 3
     *  #
     *  #
     * ##
     *
     * ess 3 by 2
     *  ##
     * ##
     *
     * ess inverse 3 by 2
     * ##
     *  ##
     */

};


#endif //RETRO_BRICK_GAME_TEXTUREBRICK_H
