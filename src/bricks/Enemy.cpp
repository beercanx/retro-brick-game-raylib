//
// Created by Beercan on 13/12/2021.
//

#include "Enemy.h"
#include "Brick.h"

Enemy::Enemy(
    const Texture2D &sprite,
    const Type type,
    float rotation,
    const Vector2 &position
) : SpriteBrick(sprite, getEnemyConfig().at(type), rotation, position),
    type(type) {
}

// Hack to do static map initialisation "safely", credit to https://qr.ae/pGqMSG
const Enemy::EnemyConfig &Enemy::getEnemyConfig() {

    static const auto *map = new EnemyConfig{
        {Type::ell,         {1, 0, 2, 3}},
        {Type::ell_inverse, {0, 0, 2, 3}},
        {Type::ess,         {3, 0, 3, 2}},
        {Type::ess_inverse, {5, 0, 3, 2}},
        {Type::line,        {1, 0, 1, 4}},
        {Type::pyramid,     {0, 1, 3, 2}},
        {Type::seat,        {1, 1, 3, 2}},
        {Type::square,      {3, 1, 2, 2}},
        {Type::step,        {6, 0, 2, 2}},
        {Type::tee,         {0, 0, 3, 3}},
        {Type::zee,         {7, 2, 3, 2}},
        {Type::zee_inverse, {5, 2, 3, 2}},
    };

    return *map;
}
