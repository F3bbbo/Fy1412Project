#include "GUI.h"
#include "StartButton.h"
#include "RotationButton.h"
#include "ResetButton.h"


GUI::GUI()
{
	nrOfButtons = 4;
	buttons = new Button*[nrOfButtons];
	//StartButton
	buttons[0] = new StartButton("Textures\\gui\\ThrustButton.png");
	buttons[0]->setSize(100, 20);
	buttons[0]->setPosition(100, 200);
	//RotationButtons
	//RightButton
	buttons[1] = new RotationButton("Textures\\gui\\RotationButton.png", 5);
	buttons[1]->setSize(40, 40);
	buttons[1]->setPosition(160, 300);
	//LeftButton
	buttons[2] = new RotationButton("Textures\\gui\\RotationButton.png", -5);
	buttons[2]->setSize(40, 40);
	buttons[2]->setPosition(100, 300);
	//ResetButton
	buttons[3] = new ResetButton();
	buttons[3]->setSize(100, 20);
	buttons[3]->setPosition(100, 250);


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
