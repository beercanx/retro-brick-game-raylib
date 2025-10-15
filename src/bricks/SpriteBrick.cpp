//
// Created by Beercan on 12/12/2021.
//

#include "SpriteBrick.h"

SpriteBrick::SpriteBrick(
    const Texture2D& sprite,
    const Rectangle& source,
    const Vector2& position
) : TextureBrick(sprite, position) {
    updateSource(source);
}

void SpriteBrick::draw() const {
    DrawTexturePro(texture, source, getDestination(), {}, 0.0f, WHITE);
}

Rectangle SpriteBrick::getDestination() const {
    return {
        position.x,
        position.y,
        width,
        height
    };
}

void SpriteBrick::updateSource(const Rectangle& value) {
    source = {
        value.x * offset,
        value.y * offset,
        value.width * offset,
        value.height * offset
    };

    width = source.width * scale;
    height = source.height * scale;
}
