#include <SFML/Graphics.hpp>
#include "StartButton.h"
#include "GUI.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Physics Project Fy1412");
	//test
	sf::Mouse mouse;
	StartButton button("Textures\\gui\\StartButton.png");
	button.setSize(100, 20);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Update
		button.update(mouse.getPosition(window), mouse.isButtonPressed(sf::Mouse::Button::Left));
		window.clear();
		window.draw(button);
		window.display();
	}

	return 0;
}