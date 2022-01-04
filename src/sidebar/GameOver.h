//
// Created by Beercan on 04/01/2022.
//

#ifndef RETRO_BRICK_GAME_GAMEOVER_H
#define RETRO_BRICK_GAME_GAMEOVER_H

class GameOver {

public:

    explicit GameOver(const Vector2 &position);

    void display();

    void draw() const;

private:

    const char* text = "Game Over!";
    const Vector2 position;

    bool active{false};

};

#endif //RETRO_BRICK_GAME_GAMEOVER_H
