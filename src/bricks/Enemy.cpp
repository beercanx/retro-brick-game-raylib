//
// Created by Beercan on 13/12/2021.
//

#include <random>
#include <utility>
#include "Enemy.h"
#include "Brick.h"
#include "raymath.h"

Enemy::Enemy(
    const Texture2D& sprite,
    const Type type,
    GameView gameView
) : SpriteBrick(sprite, getEnemyConfig().at(type), {}),
    gameView(std::move(gameView)),
    type(type)
{
    position = generatePosition();
}

// Hack to do static map initialisation "safely", credit to https://qr.ae/pGqMSG
const Enemy::EnemyConfig& Enemy::getEnemyConfig()
{
    // TODO - Look at supporting rotation, but how do we do it and still have easy collision detection?
    static const auto* map = new EnemyConfig{
        {ell, {1, 0, 2, 3}},
        {ell_inverse, {0, 0, 2, 3}},
        {ess, {3, 0, 3, 2}},
        {ess_inverse, {5, 0, 3, 2}},
        {line, {1, 0, 1, 4}},
        {pyramid, {0, 1, 3, 2}},
        {seat, {1, 1, 3, 2}},
        {square, {3, 1, 2, 2}},
        {step, {6, 0, 2, 2}},
        {tee, {0, 0, 3, 3}},
        {zee, {7, 2, 3, 2}},
        {zee_inverse, {5, 2, 3, 2}},
    };

    return *map;
}

void Enemy::handleMovement(const float deltaTime)
{
    if (!active) return;

    // Is it time to allow the next movement?
    if ((movementTime += deltaTime * static_cast<float>(speedScale)) < movementThreshold)
    {
        return;
    }

    // Reset tracker
    movementTime = 0.0f;

    // Update position
    position += down;

    // The enemy fell off the screen!
    if (position.y + height > gameView.innerBottomRight.y)
    {
        TraceLog(LOG_INFO, "Enemy got past the player");
        handleReBirth();
    }
}

void Enemy::handleDeath()
{
    active = false;
}

void Enemy::handleReBirth()
{
    static std::random_device rd;
    static std::default_random_engine generator(rd());
    static std::uniform_int_distribution<> distribution(ell, zee_inverse);

    active = true;

    type = static_cast<Type>(distribution(generator));

    updateSource(getEnemyConfig().at(type));

    // Reset back to the top with a random x position
    position = generatePosition();
}


void Enemy::draw() const
{
    if (!active) return;

    SpriteBrick::draw();
}

Rectangle Enemy::getDestination() const
{
    if (!active) return {};

    return SpriteBrick::getDestination();
}

Vector2 Enemy::generatePosition() const
{
    static std::random_device rd;
    static std::default_random_engine generator(rd());

    const int wide = static_cast<int>(width / scale / offset);

    // We have space for 8 bricks and have enemies of 1 width, which cannot be shot if in position 0 or 8.
    std::uniform_int_distribution distribution(wide == 1 ? 1 : 0, (wide == 1 ? 7 : 8) - wide);

    return gameView.innerTopLeft + right * static_cast<float>(distribution(generator)) - space;
}
