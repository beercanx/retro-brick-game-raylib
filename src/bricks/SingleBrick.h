//
// Created by Beercan on 05/12/2021.
//

#ifndef RETRO_BRICK_GAME_SINGLEBRICK_H
#define RETRO_BRICK_GAME_SINGLEBRICK_H

#include "raylib.h"
#include "TextureBrick.h"

class SingleBrick : public TextureBrick {

public:

    SingleBrick(const Texture2D &texture, int windowWidth, int windowHeight);

    void draw() override;

private:

    const int bricks{1};
    const float scale{2.0f};

    const Rectangle source{(float) texture.width, 0.0f, (float) texture.width, (float) texture.height};

    const Vector2 position;

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


#endif //RETRO_BRICK_GAME_SINGLEBRICK_H
