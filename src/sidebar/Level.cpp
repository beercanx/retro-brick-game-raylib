//
// Created by Beercan on 24/02/2022.
//

#include <iostream>
#include "Level.h"
#include "../bricks/Brick.h"

Level::Level(const Vector2 &position) : position(position) {}

void Level::draw() const {
    DrawText(
        FormatText("Level:  %07d", level),
        (int) position.x,
        (int) position.y,
        9 * Brick::scale,
        { 127, 127, 127, 255 }
    );
}

void Level::updateProgress(const int value) {
    progress += value;
    if(progress >= progressThreshold) {
        progress = 0;
        progressThreshold++;
        scoreScale++;
        speedScale++;
        level++;
        std::cout << "Level: " + std::to_string(level) << std::endl;
    }
}

int Level::getScoreScale() const {
    return scoreScale;
}

float Level::getSpeedScale() const {
    return speedScale;
}
