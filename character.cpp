#include <SFML/Graphics.hpp>
#include <string>
#include <stdlib.h>
#include "character.h"
#include <iostream>

Character::Character(int r, int x, int y) {
    body = new sf::CircleShape();
    body->setRadius(r);
    body->setPosition(x, y);
    body->setFillColor(sf::Color::Red);
    isFall = 1;
}

// control the character to move to the left with const speed 
void Character::move_left(int speed) {
    if (get_x() > 0) 
        body->move(-speed, 0);
}

// control the character to move to the right with const speed
void Character::move_right(int speed) {
    if (get_x() < 980) 
        body->move(speed, 0);
}

// draw the character to the main window
void Character::draw(sf::RenderWindow* win, double speed) {
    win->draw(*body);
    if (isFall) {
        body->move(0, 0.1 * speed);
        if (get_y() == 1500) respawn(100, 500);
    }
    else {
        body->move(0, -0.05 * speed);
        if (get_y() == 0) respawn(100, 500);
    }
}

// check if character is falling or not
bool Character::check_fall() {
    return isFall;
}

// make the character from falling to standing
void Character::stand() {
    isFall = 0;
}

// make the character from standing to falling
void Character::fall() {
    isFall = 1;
}

// return the x coordinate of the character
int Character::get_x() {
    return body->getPosition().x;;
}

// return the y coordinate of the character
int Character::get_y() {
    return body->getPosition().y;
}

// return the diameter of the character
int Character::get_size() { 
    return body->getRadius() * 2;
}

// get the current number of lives
int Character::get_life() {
    return lives;
}

// respawn randomly character after they die within the range of min_size and max_size
void Character::respawn(int max_size, int min_size) {
    int new_y = rand() % max_size + min_size;
    int new_x = rand() % max_size + min_size;
    body->setPosition(new_x, new_y);
    isFall = true;
    lives--;
}

// Destructor
Character::~Character() {};