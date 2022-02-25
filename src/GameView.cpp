//
// Created by Beercan on 25/02/2022.
//

#include "GameView.h"
#include "bricks/Brick.h"
#include "raylib/Vector2.h"

GameView::GameView(const float x, const float y, const float width, const float height) :

    width(width),
    height(height),

    outerTopLeft({x, y}),
    outerTopRight({x + width - Brick::gap * Brick::scale, y}),
    outerBottomLeft({outerTopLeft.x, y + height - Brick::gap * Brick::scale}),
    outerBottomRight({outerTopRight.x, outerBottomLeft.y}),

    innerTopLeft(outerTopLeft + Brick::right),
    innerTopRight(outerTopRight + Brick::left),
    innerBottomLeft(outerBottomLeft + Brick::right),
    innerBottomRight({innerTopRight.x, innerBottomLeft.y}) {}
