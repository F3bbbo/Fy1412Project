#include "GUI.h"
#include "StartButton.h"



GUI::GUI()
{
	nrOfButtons = 1;
	buttons = new Button*[1];
	buttons[0] = new StartButton("Textures\\gui\\StartButton.png");
	buttons[0]->setSize(100, 20);

}

GUI::~GUI()
{
	for (int i = 0; i < nrOfButtons; i++)
	{
		delete buttons[i];
	}
	delete[] buttons;
}

void GUI::update(Game & game, sf::Mouse &mouse, sf::Window &window)
{
	sf::Vector2i mousePos = mouse.getPosition(window);
	bool buttonPressed = mouse.isButtonPressed(sf::Mouse::Button::Left);
	for (int i = 0; i < nrOfButtons; i++)
	{
		buttons[i]->update(game, mousePos, buttonPressed);
	}
}

void GUI::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < nrOfButtons; i++)
	{
		target.draw(*buttons[i]);
	}
}
