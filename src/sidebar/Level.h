//
// Created by Beercan on 24/02/2022.
//

#ifndef RETRO_BRICK_GAME_LEVEL_H
#define RETRO_BRICK_GAME_LEVEL_H

#include "raylib.h"

class Level {

public:

    explicit Level(const Vector2 &position);

    void draw() const;

    void updateProgress(int value);

    int getScoreScale() const;

    float getSpeedScale() const;

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
