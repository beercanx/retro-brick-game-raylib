//
// Created by Beercan on 11/12/2021.
//

#ifndef RETRO_BRICK_GAME_BRICK_H
#define RETRO_BRICK_GAME_BRICK_H

#include "raylib.h"

class Brick
{
protected:
    ~Brick() = default;

public:
    explicit Brick(const Vector2& position);

    virtual void draw() const = 0;

    // Sizes
    static constexpr int scale{4};
    static constexpr int size{6};
    static constexpr int gap{1};
    static constexpr int offset{size + gap};

    // Movement
    constexpr static Vector2 right{offset * scale, 0.0f};
    constexpr static Vector2 left{right.x * -1.0f, right.y * -1.0f};
    constexpr static Vector2 down{0.0f, offset * scale};
    constexpr static Vector2 up{down.x * -1.0f, down.y * -1.0f};

    // Other
    constexpr static Vector2 space{gap * scale, gap * scale};

    Vector2 position{};
};

#endif //RETRO_BRICK_GAME_BRICK_H
