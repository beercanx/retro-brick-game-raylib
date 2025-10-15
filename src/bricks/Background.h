//
// Created by Beercan on 28/01/2022.
//

#ifndef RETRO_BRICK_GAME_BACKGROUND_H
#define RETRO_BRICK_GAME_BACKGROUND_H

#include <array>
#include "raylib.h"
#include "RawBrick.h"
#include "../GameView.h"

class Background
{
public:
    bool active{true};

    const GameView gameView;

    explicit Background(Vector2 position);

    void handleMovement(float deltaTime);

    void draw() const;

    void resetBackground();

    int speedScale{1};

private:
    static constexpr int width{10};
    static constexpr int height{20};

    const Vector2 position;

    std::array<std::array<RawBrick, width>, height> rawBricks;
    const std::array<std::array<RawBrick, width>, height> startingBricks;

    const float movementThreshold{0.500f}; // 500ms
    float movementTime{};

    void calculateBrickPositions();

    static void reconfigureRow(std::array<RawBrick, width>& row);
};

#endif //RETRO_BRICK_GAME_BACKGROUND_H
