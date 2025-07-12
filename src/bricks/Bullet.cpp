//
// Created by Beercan on 14/12/2021.
//

#include "Bullet.h"

Bullet::Bullet(const Vector2 &position) : RawBrick(position) {}

Rectangle Bullet::getDestination() const {
    return outerBorder;
}
