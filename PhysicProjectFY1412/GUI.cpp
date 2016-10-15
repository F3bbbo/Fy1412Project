#include "GUI.h"
#include "StartButton.h"
#include "RotationButton.h"



GUI::GUI()
{
	nrOfButtons = 3;
	buttons = new Button*[3];
	//StartButton
	buttons[0] = new StartButton("Textures\\gui\\StartButton.png");
	buttons[0]->setSize(100, 20);
	buttons[0]->setPosition(100, 100);
	//RotationButtons
	//RightButton
	buttons[1] = new RotationButton("Textures\\gui\\RotationButton.png", 5);
	buttons[1]->setSize(40, 40);
	buttons[1]->setPosition(700, 400);
	//LeftButton
	buttons[2] = new RotationButton("Textures\\gui\\RotationButton.png", -5);
	buttons[2]->setSize(40, 40);
	buttons[2]->setPosition(650, 400);


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
