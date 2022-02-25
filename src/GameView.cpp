//
// Created by Beercan on 25/02/2022.
//

#include "GameView.h"
#include "bricks/Brick.h"
#include "raylib/Vector2.h"

GameView::GameView(const Rectangle &gameView) :

    width(gameView.width),
    height(gameView.height),

    outerTopLeft({gameView.x, gameView.y}),
    outerTopRight({gameView.x + gameView.width - Brick::gap * Brick::scale, gameView.y}),
    outerBottomLeft({outerTopLeft.x, gameView.y + gameView.height - Brick::gap * Brick::scale}),
    outerBottomRight({outerTopRight.x, outerBottomLeft.y}),

    innerTopLeft(outerTopLeft + Brick::right),
    innerTopRight(outerTopRight + Brick::left),
    innerBottomLeft(outerBottomLeft + Brick::right),
    innerBottomRight({innerTopRight.x, innerBottomLeft.y}) {}
