#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Game.h"
#include <iostream>

using namespace std;
int main()
{
	Game game; // le game class
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Physics Project Fy1412");
	//test
	sf::Clock gametime;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Update
		game.Update(gametime.restart().asSeconds(),window);
		window.clear();
		window.draw(game);
		window.display();
	}

	return 0;
}