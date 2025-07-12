//
// Created by Beercan on 04/01/2022.
//

#include "raylib.h"
#include "GameOver.h"
#include "../bricks/Brick.h"

GameOver::GameOver(const Vector2 &position) : position(position) {}

void GameOver::display() {
    active = true;
}

void GameOver::draw() const {
    if (!active) return;
    DrawText(text, static_cast<int>(position.x), static_cast<int>(position.y), 10 * Brick::scale, RED);
}
