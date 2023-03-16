#pragma once

#include "character.h"

using namespace std;

class Bar {
public:
    Bar();
    void spawn(sf::RenderWindow*);
    virtual void touch(Character *character) = 0;
    bool draw(sf::RenderWindow*, double speed);
    int get_x();
    int get_y();
    int length();
    ~Bar();
protected:
    sf::RectangleShape *body;
};