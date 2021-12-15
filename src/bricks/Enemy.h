//
// Created by Beercan on 13/12/2021.
//

#ifndef RETRO_BRICK_GAME_ENEMY_H
#define RETRO_BRICK_GAME_ENEMY_H

#include <map>
#include "raylib.h"
#include "SpriteBrick.h"

class Enemy : public SpriteBrick {

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

    explicit Enemy(const Texture2D &sprite, Type type, float rotation, const Vector2 &position);

    void handleMovement(float deltaTime);

private:

    const float movementThreshold{0.500f}; // 50ms
    float movementTime{};

    const Enemy::Type type;

    typedef const std::map<Enemy::Type, Rectangle> EnemyConfig;

    const static EnemyConfig &getEnemyConfig();
};


#endif //RETRO_BRICK_GAME_ENEMY_H
