#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include "GuI.h"
#include <iostream>

using namespace std;
int main()
{
	Game game; // le game class
	GUI gui;
	sf::Mouse mouse;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Physics Project Fy1412");
	//test


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Update
		gui.update(game, mouse, window);
		game.Update(window);
		window.clear();
		window.draw(game);
		window.draw(gui);
		window.display();
	}

	return 0;
}