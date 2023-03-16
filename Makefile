mycode: Character.cpp Bar.cpp Land.cpp Trap.cpp Main.cpp
	g++ character.cpp Bar.cpp Land.cpp Trap.cpp main.cpp gui.cpp -std=c++11 -I/opt/homebrew/Cellar/sfml/2.5.1_1/include -o program -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system
	./program