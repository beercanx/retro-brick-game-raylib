//
// Created by Beercan on 12/12/2021.
//

#ifndef RETRO_BRICK_GAME_SPRITEBRICK_H
#define RETRO_BRICK_GAME_SPRITEBRICK_H

#include <map>
#include "raylib.h"
#include "TextureBrick.h"

class SpriteBrick : public TextureBrick {

public:

    enum Type {
        // Enemy
        ell,
        ell_inverse,
        ess,
        ess_inverse,
        line,
        pyramid,
        seat,
        square,
        step,
        tee,
        zee,
        zee_inverse,

        // Player
        vehicle
    };

    explicit SpriteBrick(const Texture2D &sprite, Type type, float scale, float rotation, const Vector2 &position);

    void draw() override;

protected:

    const SpriteBrick::Type type;

    typedef const std::map<SpriteBrick::Type, Rectangle> SpriteConfig;

    const static SpriteConfig &getSpriteConfig();
};

#endif //RETRO_BRICK_GAME_SPRITEBRICK_H
