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
    }),
    width(this->source.width * scale),
    height(this->source.height * scale){
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
