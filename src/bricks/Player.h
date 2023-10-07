//
// Created by Beercan on 13/12/2021.
//

#ifndef RETRO_BRICK_GAME_PLAYER_H
#define RETRO_BRICK_GAME_PLAYER_H

#include <array>
#include <optional>
#include "SpriteBrick.h"
#include "RawBrick.h"
#include "Bullet.h"
#include "../GameView.h"

class Player : public SpriteBrick {

public:

    explicit Player(const Texture2D &sprite, const Vector2 &position, GameView gameView);

    void draw() const override;

    void handleDeath();

    void handleMovement(float deltaTime);

    std::optional<Bullet> handleShooting(float deltaTime);

private:

    bool active{true};

    constexpr static const float movementThreshold{0.050f}; // 50ms
    float movementTime{};

    constexpr static const float shootingThreshold{0.250f}; // 250ms
    float shootingTime{};

    // Game boundaries
    const GameView gameView;

    Vector2 deathPosition;
    int deathSceneIndex{0};
    static const int deathSize{5};
    std::array<std::array<RawBrick, deathSize>, deathSize> deathScene = deathZero;

    std::array<std::array<RawBrick, deathSize>, deathSize> deathZero{
        {
            {true, false, false, false, true},
            {false, true, true, true, false},
            {false, true, false, true, false},
            {false, true, true, true, false},
            {true, false, false, false, true}
        }
    };

    std::array<std::array<RawBrick, deathSize>, deathSize> deathOne{
        {
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, true, false, true, false},
            {false, true, true, true, false},
            {false, false, false, false, false}
        }
    };

    std::array<std::array<RawBrick, deathSize>, deathSize> deathTwo{
        {
            {false, true, true, true, false},
            {true, false, false, false, true},
            {true, false, true, false, true},
            {true, false, false, false, true},
            {false, true, true, true, false}
        }
    };

};

#endif //RETRO_BRICK_GAME_PLAYER_H
