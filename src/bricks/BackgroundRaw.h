//
// Created by Beercan on 28/01/2022.
//

#ifndef RETRO_BRICK_GAME_BACKGROUNDRAW_H
#define RETRO_BRICK_GAME_BACKGROUNDRAW_H

#include "raylib.h"

class BackgroundRaw {

public:

    bool active{true};

    explicit BackgroundRaw(const Vector2 &position);

    void handleMovement(float deltaTime);

    Rectangle getGameView();

    void draw();

private:

    static const int width{10};
    static const int height{20};

    const Vector2 position;
    const Rectangle gameView;

    bool bricks[height][width]{
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true},
        {true, false, false, false, false, false, false, false, false, true}
    };

    const float movementThreshold{0.500f}; // 500ms
    float movementTime{};

};

#endif //RETRO_BRICK_GAME_BACKGROUNDRAW_H
