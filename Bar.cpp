#include "Bar.h"

//Constructor
Bar::Bar() {
    body = new sf::RectangleShape(sf::Vector2f(300, 5));
}

//Set the bar's initial position at the bottom of the window
void Bar::spawn(sf::RenderWindow *win) {
    int pos_x = rand() % 800;
    body->setPosition(pos_x, 1500);
}

//Display the bar on the window and move the bar
bool Bar::draw(sf::RenderWindow *win, double speed) {
    body->move(0, -0.05 * speed);
    if (body->getPosition().y >= 0.05) {
        win->draw(*body);
        return true;
    }
    else {
        spawn(win);
    }
    return false;
}

//Return the x coordinate of the bar
int Bar::get_x() {
    return body->getPosition().x;
}

//Return the y coordinate of the bar
int Bar::get_y() {
    return body->getPosition().y;
}

//Return the length of the bar
int Bar::length() {
    return body->getSize().x;
}

//Destructor
Bar::~Bar() {
    delete body;
}