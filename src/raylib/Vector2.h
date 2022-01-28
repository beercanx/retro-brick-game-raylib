//
// Created by Beercan on 28/01/2022.
//

#ifndef RETRO_BRICK_GAME_VECTOR2_H
#define RETRO_BRICK_GAME_VECTOR2_H

#include "raylib.h"

Vector2 operator+(const Vector2 &v1, const Vector2 &v2);

Vector2 operator-(const Vector2 &v1, const Vector2 &v2);

Vector2 operator*(const Vector2 &a, float scale);

Vector2 operator*(const Vector2 &v, int scale);

Vector2 operator*(const Vector2 &v1, const Vector2 &v2);

Vector2 operator/(const Vector2 &v1, const Vector2 &v2);

Vector2& operator+=(Vector2& v1, const Vector2& v2);

Vector2& operator-=(Vector2& v1, const Vector2& v2);

Vector2& operator*=(Vector2& v1, float scale);

Vector2& operator*=(Vector2& v1, const Vector2& v2);

Vector2& operator/=(Vector2& v1, const Vector2& v2);

#endif //RETRO_BRICK_GAME_VECTOR2_H
