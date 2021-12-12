//
// Created by Beercan on 12/12/2021.
//

#include "SpriteBrick.h"

SpriteBrick::SpriteBrick(
    const Texture2D &sprite,
    const SpriteBrick::Type type,
    float scale,
    float rotation,
    const Vector2 &position
) : TextureBrick(sprite, scale, rotation, position),
    type(type) {
}

// Hack to do static map initialisation "safely", credit to https://qr.ae/pGqMSG
const SpriteBrick::SpriteConfig &SpriteBrick::getSpriteConfig() {

    static const int offset{Brick::size + Brick::gap};

    static const auto *map = new SpriteConfig{
        // Enemy
        {Type::ell,         {1 * offset, 0 * offset, 2 * offset, 3 * offset}},
        {Type::ell_inverse, {0 * offset, 0 * offset, 2 * offset, 3 * offset}},
        {Type::ess,         {3 * offset, 0 * offset, 3 * offset, 2 * offset}},
        {Type::ess_inverse, {5 * offset, 0 * offset, 3 * offset, 2 * offset}},
        {Type::line,        {1 * offset, 0 * offset, 1 * offset, 4 * offset}},
        {Type::pyramid,     {0 * offset, 1 * offset, 3 * offset, 2 * offset}},
        {Type::seat,        {1 * offset, 1 * offset, 3 * offset, 2 * offset}},
        {Type::square,      {3 * offset, 1 * offset, 2 * offset, 2 * offset}},
        {Type::step,        {6 * offset, 0 * offset, 2 * offset, 2 * offset}},
        {Type::tee,         {0 * offset, 0 * offset, 3 * offset, 3 * offset}},
        {Type::zee,         {7 * offset, 2 * offset, 3 * offset, 2 * offset}},
        {Type::zee_inverse, {5 * offset, 2 * offset, 3 * offset, 2 * offset}},

        // Player
        {Type::vehicle,     {9 * offset, 0 * offset, 3 * offset, 4 * offset}}
    };

    return *map;
}

void SpriteBrick::draw() {

    const Vector2 origin{0.0f, 0.0f};
    const Rectangle source{getSpriteConfig().at(type)};
    const Rectangle dest{position.x, position.y, (float) source.width * scale, (float) source.height * scale};

    DrawTexturePro(texture, source, dest, origin, rotation, WHITE);
}