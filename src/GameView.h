//
// Created by Beercan on 25/02/2022.
//

#ifndef RETRO_BRICK_GAME_GAMEVIEW_H
#define RETRO_BRICK_GAME_GAMEVIEW_H

#include "raylib.h"

class GameView
{
public:
    explicit GameView(float x, float y, float width, float height);

    const Rectangle outer;
    const Vector2 outerTopLeft;
    const Vector2 outerTopRight;
    const Vector2 outerBottomLeft;
    const Vector2 outerBottomRight;

    const Rectangle inner;
    const Vector2 innerTopLeft;
    const Vector2 innerTopRight;
    const Vector2 innerBottomLeft;
    const Vector2 innerBottomRight;

    const Rectangle border;
};

#endif //RETRO_BRICK_GAME_GAMEVIEW_H
