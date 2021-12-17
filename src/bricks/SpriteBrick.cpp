//
// Created by Beercan on 12/12/2021.
//

#include "SpriteBrick.h"

SpriteBrick::SpriteBrick(
    const Texture2D &sprite,
    const Rectangle source,
    const Vector2 &position
) : TextureBrick(sprite, position),
    source({
        (source.x * offset) - gap,
        (source.y * offset) - gap,
        source.width * offset,
        source.height * offset
    }) {
    updatePosition(position);
}

void SpriteBrick::updatePosition(const Vector2 &position) {

    this->position = position;

    // Recalculate destination
    destination = {
        position.x,
        position.y,
        (float) source.width * scale,
        (float) source.height * scale
    };
}

Rectangle SpriteBrick::getDestination() {
    return destination;
}

void SpriteBrick::draw() {

    const Vector2 origin{1.0f, 1.0f};

    DrawTexturePro(texture, source, destination, origin, 0.0f, WHITE);
}
