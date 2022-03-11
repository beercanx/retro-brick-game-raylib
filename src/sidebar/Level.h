//
// Created by Beercan on 24/02/2022.
//

#ifndef RETRO_BRICK_GAME_LEVEL_H
#define RETRO_BRICK_GAME_LEVEL_H

#include "raylib.h"
#include <list>
#include <functional>

class Level {

public:

    explicit Level(const Vector2 &position);

    void draw() const;

    void updateProgress(int value);

    [[deprecated("Replaced by onScoreScaleChange events")]] int getScoreScale() const;

    [[deprecated("Replaced by onSpeedScaleChange events")]] float getSpeedScale() const;

    // Events
    std::list<std::function<void(int level)>> onLevelChange{};
    std::list<std::function<void(int scoreScale)>> onScoreScaleChange{};
    std::list<std::function<void(int speedScale)>> onSpeedScaleChange{};

private:

    const Vector2 position;

    static const int max{9999999};

    int level{1};

    int progress{0};
    int progressThreshold{5};

    // Difficulty
    int scoreScale{1};
    float speedScale{1};
};

#endif //RETRO_BRICK_GAME_LEVEL_H
