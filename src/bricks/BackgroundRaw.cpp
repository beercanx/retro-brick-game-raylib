//
// Created by Beercan on 28/01/2022.
//

#include "BackgroundRaw.h"
#include "Brick.h"
#include "RawBrick.h"
#include "../raylib/Vector2.h"

BackgroundRaw::BackgroundRaw(const Vector2 &position) :
    position(position),
    gameView(
        {
            position.x,
            position.y,
            BackgroundRaw::width * Brick::offset * Brick::scale,
            BackgroundRaw::height * Brick::offset * Brick::scale
        }
    ) {
}

Rectangle BackgroundRaw::getGameView() {
    return gameView;
}

void BackgroundRaw::handleMovement(float deltaTime) {
    // TODO - Implement it
}

void BackgroundRaw::draw() {
    for (int widthIndex = 0; widthIndex < BackgroundRaw::width; ++widthIndex) {
        for (int heightIndex = 0; heightIndex < BackgroundRaw::height; ++heightIndex) {
            if (bricks[heightIndex][widthIndex]) {

                // TODO - Probably more performant to track the RawBricks and update to disable their rendering.

                RawBrick brick{
                    {
                        position
                        + (Brick::right * (float) widthIndex)
                        + (Brick::down * (float) heightIndex)
                    }
                };

                brick.draw();
            }
        }
    }
}
