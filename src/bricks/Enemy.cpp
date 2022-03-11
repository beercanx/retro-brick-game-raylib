//
// Created by Beercan on 13/12/2021.
//

#include <random>
#include <iostream>
#include "Enemy.h"
#include "Brick.h"
#include "../raylib/Vector2.h"

Enemy::Enemy(
    const Texture2D &sprite,
    const Type type,
    const GameView gameView
) : SpriteBrick(sprite, getEnemyConfig().at(type), {}),
    type(type),
    gameView(gameView) {
    position = generatePosition();
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

void Enemy::handleMovement(const float deltaTime) {

    if (!active) return;

    // Is it time to allow the next movement?
    if ((movementTime += deltaTime * (float) speedScale) < movementThreshold) {
        return;
    }

    // Reset tracker
    movementTime = 0.0f;

    // Update position
    position += Brick::down;

    // The enemy fell off the screen!
    if (position.y + height > gameView.innerBottomRight.y) {
        std::cout << "Enemy got past the player" << std::endl;
        handleReBirth();
    }
}

void Enemy::handleDeath() {

    active = false;
}

void Enemy::handleReBirth() {

    static std::random_device rd;
    static std::default_random_engine generator(rd());
    static std::uniform_int_distribution<int> distribution(Type::ell, Type::zee_inverse);

    active = true;

    type = static_cast<Type>(distribution(generator));

    updateSource(getEnemyConfig().at(type));

    // Reset back to the top with a random x position
    position = generatePosition();
}


void Enemy::draw() {

    if (!active) return;

    SpriteBrick::draw();
}

Rectangle Enemy::getDestination() {

    if (!active) return {};

    return SpriteBrick::getDestination();
}

Vector2 Enemy::generatePosition() {

    static std::random_device rd;
    static std::default_random_engine generator(rd());

    const int wide = (int) (width / scale / offset);

    // We have space for 8 bricks and have enemies of 1 width, which cannot be shot if in position 0 or 8.
    std::uniform_int_distribution<int> distribution(wide == 1 ? 1 : 0, (wide == 1 ? 7 : 8) - wide);

    return gameView.innerTopLeft + (Brick::right * distribution(generator)) - Brick::space;
}
