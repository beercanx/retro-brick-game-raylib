//
// Created by Beer on 05/12/2021.
//

#include "TextureBrick.h"

TextureBrick::TextureBrick(int windowWidth, int windowHeight) :
    position({(float) windowWidth / 2.0f, (float) windowHeight / 2.0f}),
    destination({position.x, position.y, (float) brick.width, (float) brick.height}) {}

void TextureBrick::draw() {
    //DrawTexturePro(brick, source, destination, Vector2{}, 0.0f, WHITE);
    DrawTextureEx(brick, position, 0.0f, scale, WHITE);
}

void TextureBrick::unloadTextures() {
    UnloadTexture(brick);
}
