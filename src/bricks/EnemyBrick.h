//
// Created by Beercan on 13/12/2021.
//

#ifndef RETRO_BRICK_GAME_ENEMYBRICK_H
#define RETRO_BRICK_GAME_ENEMYBRICK_H

#include <map>
#include "raylib.h"
#include "SpriteBrick.h"

class EnemyBrick : public SpriteBrick {

public:

    enum Type {
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
        zee_inverse
    };

    explicit EnemyBrick(const Texture2D &sprite, Type type, float rotation, const Vector2 &position);

private:

    const EnemyBrick::Type type;

    typedef const std::map<EnemyBrick::Type, Rectangle> EnemyConfig;

    const static EnemyConfig &getEnemyConfig();
};


#endif //RETRO_BRICK_GAME_ENEMYBRICK_H
