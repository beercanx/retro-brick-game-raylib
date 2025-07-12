//
// Created by Beercan on 13/12/2021.
//

#ifndef RETRO_BRICK_GAME_ENEMY_H
#define RETRO_BRICK_GAME_ENEMY_H

#include <map>
#include "raylib.h"
#include "SpriteBrick.h"
#include "../GameView.h"

class Enemy final : public SpriteBrick {

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

    explicit Enemy(const Texture2D &sprite, Type type, GameView  gameView);

    void draw() const override;

    void handleMovement(float deltaTime);

    void handleDeath();

    void handleReBirth();

    [[nodiscard]] Rectangle getDestination() const override;

    int speedScale{1};

private:

    // TODO - Replace with rebirth
    bool active{true};

    const float movementThreshold{0.500f}; // 500ms
    float movementTime{};

    const GameView gameView;

    Type type;
    typedef const std::map<Type, Rectangle> EnemyConfig;
    const static EnemyConfig &getEnemyConfig();

    [[nodiscard]] Vector2 generatePosition() const;

};


#endif //RETRO_BRICK_GAME_ENEMY_H
