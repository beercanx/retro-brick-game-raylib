//
// Created by Beercan on 05/12/2021.
//

#include "RawBrick.h"

RawBrick::RawBrick(const Vector2 &position) : Brick(position) {
    updatePosition(position);
}

// Is used by the array initializer of BackgroundRaw::rawBricks
RawBrick::RawBrick(const bool visible) : Brick({}) {
    this->visible = visible;
}

void RawBrick::draw() {

    // Don't render, you're not visible
    if (!visible) return;

    // outer square, 6 by 6, gray (7F7F7F)
    DrawRectangleRec(outerBorder, GRAY);

    // inner border, 4 by 4, white
    DrawRectangleRec(innerBorder, WHITE);

    // centre square, 2 by 2, black
    DrawRectangleRec(center, BLACK);
}

void RawBrick::updatePosition(const Vector2 &position) {

    this->position = position;

    this->outerBorder = {position.x, position.y, scale * 6, scale * 6};
    this->innerBorder = {position.x + (scale * 1), position.y + (scale * 1), scale * 4, scale * 4};
    this->center = {position.x + scale * 2, position.y + scale * 2, scale * 2, scale * 2};
}
