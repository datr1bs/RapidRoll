#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Character {
    private:
        sf::CircleShape* body;
        int lives = 5;
        bool isFall = true;
    public:
        Character(int r, int x, int y);
        void move_left(int speed);
        void move_right(int speed);
        void draw(sf::RenderWindow *win, double speed);
        void respawn(int max_size, int min_size);
        bool check_fall();
        int get_life();
        int get_x();
        int get_y();
        int get_size();
        void stand();
        void fall();
        ~Character();
};