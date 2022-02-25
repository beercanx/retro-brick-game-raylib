//
// Created by Beercan on 25/02/2022.
//

#include "GameView.h"
#include "bricks/Brick.h"

GameView::GameView(const float x, const float y, const float width, const float height) :

    outer({x, y, width, height}),
    outerTopLeft({outer.x, outer.y}),
    outerTopRight({outer.x + outer.width, outer.y}),
    outerBottomLeft({outer.x, outer.y + outer.height}),
    outerBottomRight({outerTopRight.x, outerBottomLeft.y}),

    inner({x + Brick::right.x, y + Brick::left.y, width - Brick::right.x * 2, height - Brick::left.y * 2}),
    innerTopLeft({inner.x, inner.y}),
    innerTopRight({inner.x + inner.width, inner.y}),
    innerBottomLeft({inner.x, inner.y + inner.height}),
    innerBottomRight({innerTopRight.x, innerBottomLeft.y}) {}
