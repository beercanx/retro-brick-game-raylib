//
// Created by Beercan on 04/01/2022.
//

#include "Score.h"
#include "../bricks/Brick.h"

Score::Score(const Vector2 &position) : position(position) {}

void Score::increase() {
    if (score >= max) return;
    score += scoreScale;
    if (score >= max) score = max;
}

void Score::draw() const {
    DrawText(
        TextFormat("Score: %07d", score),
        static_cast<int>(position.x),
        static_cast<int>(position.y),
        9 * Brick::scale,
        { 127, 127, 127, 255 }
    );
}
