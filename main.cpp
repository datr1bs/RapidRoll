#include <SFML/Graphics.hpp>
#include "character.h"
#include "Bar.h"
#include "Land.h"
#include "Trap.h"
#include "gui.h"
#include <math.h>
#include <string>

class Game {
    // declare variables for the class
    private:
        sf::RenderWindow *win;
        Character* character;
        int _score = 0;
        int _speed = 1;
        int window_size;
        sf::Text Text;
        sf::Font Font;

    public:
        // Init value for all variables
        Game(int size, std::string title, int speed) {
            win = new sf::RenderWindow(sf::VideoMode(size, size + 500), title, sf::Style::Close);
            character = new Character(10, 50, 50);
            _speed = speed;
            window_size = size;
            // check if font can be loaded
            if (!Font.loadFromFile("QUICKENS.ttf")) {
                exit(0);
            }
            // add setting for all the text in menu window
            Text.setFont(Font);
            Text.setFillColor(sf::Color::White);
            Text.setCharacterSize(25); 
        }

        // run the whole game  
        void run() {
            int speed_bar = 1;
            sf::Clock clock;
            vector<Bar*> v;
            sf::RenderWindow *gui_win = new sf::RenderWindow(sf::VideoMode(window_size, window_size + 500), "Game Menu", sf::Style::Close);
            GUI *gui = new GUI(window_size, window_size);
            
            // Open GUI window
            while(gui_win->isOpen()) {
                sf::Event menu_event;
                while(gui_win->pollEvent(menu_event)) {
                    if (menu_event.type == sf::Event::Closed || menu_event.key.code == sf::Keyboard::Q)
                        gui_win->close();
                    // check if users click the mouseButton to the Play or Quit buttons
                    if (menu_event.type == sf::Event::MouseButtonPressed) {
                        // click play button
                        if (menu_event.mouseButton.y <= 370 && menu_event.mouseButton.y >= 300 && menu_event.mouseButton.x >= 400 && menu_event.mouseButton.x <= 570) {
                            while (win->isOpen() && character->get_life() > 0) {
                                sf::Event event; 
                                sf::Time elapsed1 = clock.getElapsedTime();
                                int sec_1 = elapsed1.asSeconds();
                                
                                while ( win->pollEvent(event)) {
                                    if (event.type == sf::Event::Closed)
                                        win->close();
                                    // Press A to move left, D to move right
                                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                                        character->move_left(_speed);
                                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                                        character->move_right(_speed);
                                }
                                
                                // Display info about Game : lives, scores 
                                std::string info;
                                info = "Score " + std::to_string(sec_1) + "\n" + "Lives " + std::to_string(character->get_life()) + " ";
                                Text.setString(info);

                                // Spawn 10 bars to the game
                                if (v.empty() || (v.size() < 10 && v.back()->get_y() == 1350)) {
                                    Bar *A;
                                    if (v.size() % 3 == 0) 
                                        A = new Trap;
                                    else 
                                        A = new Land;
                                    A->spawn(win);
                                    v.push_back(A);
                                } 
                                int n = v.size();
                                // draw bars to window
                                for (int i = 0; i < n; ++i) {
                                    v[i]->touch(character);
                                    v[i]->draw(win, speed_bar);
                                }
                                // Turn of the menu window and draw everything to the window and clear the screen
                                gui_win->close();
                                character->draw(win, speed_bar);
                                win->draw(Text);
                                win->display();
                                win->clear();
                            }
                        }
                        // click quit button
                        else if (menu_event.mouseButton.y >= 400 && menu_event.mouseButton.y <= 470 && menu_event.mouseButton.x >= 400 && menu_event.mouseButton.x <= 560) {
                            gui_win->close();
                        }
                        break;
                    }
                }
                gui_win->clear();
                gui->draw(gui_win);
                gui_win->display();
            }
        }
        // delete variables from the heap
        ~Game(){
            delete win;
            delete character;
        };
};


int main() {
    while (1) {
        string s;
        cout << "PRESS H TO SHOW HELP OR PRESS P TO START THE GAME:  ";
        cin >> s;
        cout << '\n';
        if (s == "h" || s == "H") {
            cout << "*******HELP*******\n";
            cout << "WHEN THE MENU APPEARS, PRESS START TO START THE GAME\n";
            cout << "OR PRESS QUIT TO QUIT THE GAME\n";
            cout << "\n******************\n";
            cout << "YOU ARE CONTROLLING A CIRCLE-SHAPED CHARACTER\n";
            cout << "YOU HAVE ONLY 3 LIVES\n";
            cout << "YOUR GOAL IS TO SURVIVE AS LONG AS POSSIBLE\n";
            cout << "\n******************\n";
            cout << "HOW TO PLAY: \n";
            cout << "PRESS A TO MOVE LEFT\nPRESS D MOVE RIGHT\n";
            cout << "YOU CAN LAND ON THE GREEN BAR\n";
            cout << "HOWEVER, IF YOU TOUCH THE RED BAR\nOR THE TOP OR BOTTOM EDGE OF THE WINDOW\nYOU WILL LOSE A LIFE\n";
            cout << "THE GAME WILL AUTOMATICALLY QUIT WHEN YOU LOSE ALL LIVES\n";
            cout << "\n-----HAVE FUN------\n\n";
        }
        else if (s == "p" || s == "P") {
            Game game(1000, "OOP Game", 4);
            game.run();
            break;
        }
        else cout << "INVALID! PLEASE TRY AGAIN\n";
    }
    return 0;
}