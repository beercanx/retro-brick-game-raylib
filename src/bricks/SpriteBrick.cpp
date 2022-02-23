//
// Created by Beercan on 12/12/2021.
//

#include "SpriteBrick.h"

SpriteBrick::SpriteBrick(
    const Texture2D &sprite,
    const Rectangle source,
    const Vector2 &position
) : TextureBrick(sprite, position) {
    updateSource(source);
}

Rectangle SpriteBrick::getDestination() {
    return {
        position.x,
        position.y,
        width,
        height
    };
}

void SpriteBrick::draw() {

    const Vector2 origin{1.0f, 1.0f};

    DrawTexturePro(texture, source, getDestination(), origin, 0.0f, WHITE);
}

void SpriteBrick::updateSource(const Rectangle value) {

    source = {
        (value.x * offset) - gap,
        (value.y * offset) - gap,
        value.width * offset,
        value.height * offset
    };

    width = source.width * scale;
    height = source.height * scale;
}
