//
// Created by Beercan on 13/12/2021.
//

#include <iostream>
#include "Background.h"

Background::Background(const Texture2D &texture, const Rectangle &source, const Vector2 &position) :
    texture(texture),
    source({
       (source.x * Brick::offset) - Brick::gap,
       (source.y * Brick::offset) - Brick::gap,
       source.width * Brick::offset,
       source.height * Brick::offset
    }),
    destination({
        position.x,
        position.y,
        this->source.width * Brick::scale,
        this->source.height * Brick::scale
    }),
    originalSource({this->source}),
    originalDestination({this->destination}) {}

void Background::handleMovement(const float deltaTime) {

    // Stop moving, you're not active at the moment.
    if (!active) return;

    // Is it time to allow the next movement?
    if ((movementTime += deltaTime) < movementThreshold) {
        return;
    }

    // Reset tracker
    movementTime = 0.0f;

    // Update the source height by one brick.
    source.height -= Brick::offset;

    // Move the position in the world down by one brick and shorter by one brick.
    destination.x += Brick::down.x;
    destination.y += Brick::down.y;
    destination.height -= Brick::offset * Brick::scale;

    if(source.height <= 0 || destination.height <= 0) {
        std::cout << "Resetting the background" << std::endl;
        source = originalSource;
        destination = originalDestination;
    }
}

Rectangle Background::getGameView() {
    return originalDestination;
}

void Background::draw() {
    DrawTexturePro(texture, source, destination, {}, 0.0f, WHITE);
}
