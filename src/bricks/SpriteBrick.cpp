//
// Created by Beercan on 12/12/2021.
//

#include "SpriteBrick.h"

SpriteBrick::SpriteBrick(
    const Texture2D &sprite,
    const Rectangle source,
    float rotation,
    const Vector2 &position
) : TextureBrick(sprite, rotation, position),
    source({source.x * offset, source.y * offset, source.width * offset, source.height * offset}) {
}

void SpriteBrick::draw() {
    DrawBrick(texture, source, position, scale, rotation, WHITE);
}