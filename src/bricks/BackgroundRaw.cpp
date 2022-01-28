//
// Created by Beercan on 28/01/2022.
//

#include "BackgroundRaw.h"
#include "Brick.h"
#include "../raylib/Vector2.h"

BackgroundRaw::BackgroundRaw(const Vector2 &position) :
    position(position),
    gameView(
        {
            position.x,
            position.y,
            width * Brick::offset * Brick::scale,
            height * Brick::offset * Brick::scale
        }
    ) {
    // Initialise the position of each RawBrick.
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

Rectangle BackgroundRaw::getGameView() {
    return gameView;
}

void BackgroundRaw::handleMovement(float deltaTime) {
    // TODO - Implement it
}

void BackgroundRaw::draw() {
    for (auto &row: rawBricks) {
        for (auto &brick: row) {
            if (brick.visible) {
                brick.draw();
            }
        }
    }
}
