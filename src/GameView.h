//
// Created by Beercan on 25/02/2022.
//

#ifndef RETRO_BRICK_GAME_GAMEVIEW_H
#define RETRO_BRICK_GAME_GAMEVIEW_H

#include "raylib.h"

class GameView {

public:

    explicit GameView(const Rectangle &gameView);

    const float width;
    const float height;

    const Vector2 outerTopLeft;
    const Vector2 outerTopRight;
    const Vector2 outerBottomLeft;
    const Vector2 outerBottomRight;

    const Vector2 innerTopLeft;
    const Vector2 innerTopRight;
    const Vector2 innerBottomLeft;
    const Vector2 innerBottomRight;

};

#endif //RETRO_BRICK_GAME_GAMEVIEW_H
