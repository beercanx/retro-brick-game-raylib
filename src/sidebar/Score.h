//
// Created by Beercan on 04/01/2022.
//

#ifndef RETRO_BRICK_GAME_SCORE_H
#define RETRO_BRICK_GAME_SCORE_H

#include "raylib.h"

class Score {

public:

    explicit Score(const Vector2 &position);

    void increase();

    void draw() const;

    int scoreScale{1};

private:

    const Vector2 position;

    static constexpr int max{9999999};

    int score{0};

};

#endif //RETRO_BRICK_GAME_SCORE_H
