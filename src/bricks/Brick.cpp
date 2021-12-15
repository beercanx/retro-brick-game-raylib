//
// Created by Beercan on 11/12/2021.
//

#include "Brick.h"

Brick::Brick(
    const float rotation,
    const Vector2 &position
) : rotation(rotation),
    position(position) {}

void DrawBrick(
    const Texture texture,
    const Rectangle source,
    const Vector2 position,
    const float scale,
    const float rotation,
    const Color tint
) {

    const Vector2 origin{1.0f, 1.0f};
    const Rectangle destination{
        position.x,
        position.y,
        (float) source.width * scale,
        (float) source.height * scale
    };

    DrawTexturePro(texture, source, destination, origin, rotation, tint);
}