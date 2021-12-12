//
// Created by Beercan on 05/12/2021.
//

#include "RawBrick.h"

RawBrick::RawBrick(
    const float scale,
    const float rotation,
    const Vector2 &position
) : Brick(scale, rotation, position),
    outerBorder({position.x, position.y, scale * 6, scale * 6}),
    innerBorder({position.x + (scale * 1), position.y + (scale * 1), scale * 4, scale * 4}),
    center({position.x + scale * 2, position.y + scale * 2, scale * 2, scale * 2}) {}

void RawBrick::draw() {

    // outer square, 6 by 6, gray (7F7F7F)
    DrawRectangleRec(outerBorder, GRAY);

    // inner border, 4 by 4, white
    DrawRectangleRec(innerBorder, WHITE);

    // centre square, 2 by 2, black
    DrawRectangleRec(center, BLACK);
}
