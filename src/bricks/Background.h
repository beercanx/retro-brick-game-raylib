//
// Created by Beercan on 13/12/2021.
//

#ifndef RETRO_BRICK_GAME_BACKGROUND_H
#define RETRO_BRICK_GAME_BACKGROUND_H

#include "raylib.h"
#include "SpriteBrick.h"

class Background {

public:

    explicit Background(const Texture2D &texture, const Rectangle &source, const Vector2 &position);

    constexpr static const Rectangle START{0, 0, 10, 20};
    constexpr static const Rectangle IN_PROGRESS{0, 0, 10, 20};

    bool active{true};

    void handleMovement(float deltaTime);

    Rectangle getGameView();

    void draw();

private:

    const Texture2D texture;

    const float movementThreshold{0.500f}; // 500ms
    float movementTime{};

    Rectangle source;
    Rectangle destination;

    Rectangle originalSource;
    Rectangle originalDestination;

};


#endif //RETRO_BRICK_GAME_BACKGROUND_H
