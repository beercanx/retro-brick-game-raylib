//
// Created by Beercan on 28/01/2022.
//

#include "Vector2.h"

Vector2 operator+(const Vector2 &v1, const Vector2 &v2) {
    return {v1.x + v2.x, v1.y + v2.y};
}

Vector2 operator-(const Vector2 &v1, const Vector2 &v2) {
    return {v1.x - v2.x, v1.y - v2.y};
}

Vector2 operator*(const Vector2 &v, float scale) {
    return {v.x * scale, v.y * scale};
}

Vector2 operator*(const Vector2 &v1, const Vector2 &v2) {
    return {v1.x * v2.x, v1.y * v2.y};
}

Vector2 operator/(const Vector2 &v1, const Vector2 &v2) {
    return {v1.x / v2.x, v1.y / v2.y};
}

Vector2 &operator+=(Vector2 &v1, const Vector2 &v2) {
    v1.x += v2.x;
    v1.y += v2.y;
    return v1;
}

Vector2& operator-=(Vector2& v1, const Vector2& v2) {
    v1.x -= v2.x;
    v1.y -= v2.y;
    return v1;
}

Vector2 &operator*=(Vector2 &v1, const float scale) {
    v1.x *= scale;
    v1.y *= scale;
    return v1;
}

Vector2 &operator*=(Vector2 &v1, const Vector2 &v2) {
    v1.x *= v2.x;
    v1.y *= v2.y;
    return v1;
}

Vector2& operator/=(Vector2& v1, const Vector2& v2) {
    v1.x /= v2.x;
    v1.y /= v2.y;
    return v1;
}