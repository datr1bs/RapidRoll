#include <iostream>
#include <SFML/Graphics.hpp>

class GUI {
    public:
        GUI(int height, int width);
        void draw(sf::RenderWindow *window);
        ~GUI();
    
    private:
        sf::Font font;
        sf::Text menu[2];
        sf::Text GameName;
};