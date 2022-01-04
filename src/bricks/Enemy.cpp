//
// Created by Beercan on 13/12/2021.
//

#include "Enemy.h"
#include "Brick.h"

Enemy::Enemy(
    const Texture2D &sprite,
    const Type type,
    const Vector2 &position
) : SpriteBrick(sprite, getEnemyConfig().at(type), position),
    type(type) {
}

// Hack to do static map initialisation "safely", credit to https://qr.ae/pGqMSG
const Enemy::EnemyConfig &Enemy::getEnemyConfig() {

    // TODO - Look at supporting rotation, but how do we do it and still have easy collision detection?
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

void Enemy::handleMovement(float deltaTime) {

    if(!active) return;

    // Is it time to allow the next movement?
    if ((movementTime += deltaTime) < movementThreshold) {
        return;
    }

    // Reset tracker
    movementTime = 0.0f;

    // TODO - Update position
    //updatePosition();
}

void Enemy::handleDeath() {

    active = false;
}

void Enemy::draw() {

    if(!active) return;

    SpriteBrick::draw();
}

Rectangle Enemy::getDestination() {

    if(!active) return {};

    return SpriteBrick::getDestination();
}
