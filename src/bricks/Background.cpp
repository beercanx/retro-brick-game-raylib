//
// Created by Beercan on 28/01/2022.
//

#include "Background.h"
#include "Brick.h"
#include "../raylib/Vector2.h"

Background::Background(const Vector2 position) :
    position(position),
    gameView{
        position.x,
        position.y,
        width * Brick::offset * Brick::scale - Brick::space.x,
        height * Brick::offset * Brick::scale - Brick::space.y
    },
    rawBricks{{ // Starting Background
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
    }} {
    // Initialise the position of each RawBrick.
    calculateBrickPositions();
}

void Background::handleMovement(float deltaTime) {

    // Stop moving, you're not active at the moment.
    if (!active) return;

    // Is it time to allow the next movement?
    if ((movementTime += deltaTime) < movementThreshold) {
        return;
    }

    // Reset tracker
    movementTime = 0.0f;

    // TODO - on new level reset the background

    // Shift down each row by one
    // Take the last row and move it to the first.
    auto lastRow = rawBricks[height - 1];
    for (int index = height - 1; index > 0; index--) {
        // Shift each row down by one
        rawBricks[index] = rawBricks[index - 1];
    }
    reconfigureRow(lastRow);
    rawBricks[0] = lastRow;

    // Recalculate brick positions
    calculateBrickPositions();
}

void Background::draw() {
    for (auto &row: rawBricks) {
        for (auto &brick: row) {
            if (brick.visible) {
                brick.draw();
            }
        }
    }
    DrawRectangleLinesEx(gameView.border, 1.0f, BLACK);
}

void Background::calculateBrickPositions() {
    for (int widthIndex = 0; widthIndex < width; ++widthIndex) {
        for (int heightIndex = 0; heightIndex < height; ++heightIndex) {
            rawBricks[heightIndex][widthIndex].updatePosition(
                position
                + (Brick::right * widthIndex)
                + (Brick::down * heightIndex)
            );
        }
    }
}

void Background::reconfigureRow(std::array<RawBrick, width> &row) {
    static int step{0};

    row.front().visible = step != 0;
    row.back().visible = step != 0;

    if(++step > 2) {
        step = 0;
    }
}
