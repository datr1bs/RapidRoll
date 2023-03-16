#include "Land.h"

//Constructor
Land::Land() {
    body->setFillColor(sf::Color::Green);
}

//Make character stand if touched and fall if moving out of its length
void Land::touch(Character* character) {
    if (character->get_y() + character->get_size() == get_y()) {
        int char_x = character->get_x();
        int bar_x = get_x();
        if (char_x >= bar_x - character->get_size() && char_x <= bar_x + length()) 
            character->stand();
        else 
            character->fall();
    }
}

//Destructor
Land::~Land() {

}
    