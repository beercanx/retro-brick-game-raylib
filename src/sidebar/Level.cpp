//
// Created by Beercan on 24/02/2022.
//

#include <iostream>
#include "raylib.h"
#include "Level.h"
#include "../bricks/Brick.h"

Level::Level(const Vector2 &position) : position(position) {

    onLevelChange.emplace_back([](int lvl) -> void {
        TraceLog(LOG_INFO, ("Level: " + std::to_string(lvl)).c_str());
    });

    onScoreScaleChange.emplace_back([](int score) -> void {
        TraceLog(LOG_INFO, ("Score Multiplier: " + std::to_string(score)).c_str());
    });

    onSpeedScaleChange.emplace_back([](int speed) -> void {
        TraceLog(LOG_INFO, ("Speed Multiplier: " + std::to_string(speed)).c_str());
    });
}

void Level::draw() const {
    DrawText(
        TextFormat("Level:  %07d", level),
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
        progressThreshold *= 2;

        level++;
        std::for_each(onLevelChange.begin(), onLevelChange.end(), [&](const auto& listener){
            // TODO - on new level pause for a few seconds and increment the score a bit.
            listener(level);
        });

        scoreScale++;
        std::for_each(onScoreScaleChange.begin(), onScoreScaleChange.end(), [&](const auto& listener){
            listener(scoreScale);
        });

        speedScale++;
        std::for_each(onSpeedScaleChange.begin(), onSpeedScaleChange.end(), [&](const auto& listener){
            listener(speedScale);
        });
    }
}
