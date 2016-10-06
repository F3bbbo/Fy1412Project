#include "Button.h"

Button::Button()
{

}

Button::Button(std::string spriteFileName)
{
	if (buttonTexture.loadFromFile(spriteFileName))
	{
		buttonSprite.setTexture(buttonTexture);
	}
	else
	{
		std::cout << "Coudln't load file: " << spriteFileName << std::endl;
	}
	buttonSprite.setPosition(100, 100);
}

Button::~Button()
{

}



void Button::update(Game &game, sf::Vector2i mousePos, bool buttonPressed)
{
	sf::FloatRect boundingBox;
	boundingBox = buttonSprite.getGlobalBounds();
	if (boundingBox.contains(mousePos.x, mousePos.y))
	{
		if (buttonPressed)
		{
			clickedLastFrame = true;
		}
		else if (clickedLastFrame)
		{
			onClick();
			clickedLastFrame = false;
		}
	}
	else
	{
		clickedLastFrame = false;
	}

}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(buttonSprite);
}

void Button::setPosition(float x, float y)
{
	buttonSprite.setPosition(x, y);
}

void Button::setSize(float x, float y)
{
	sf::FloatRect tmpRect = buttonSprite.getGlobalBounds();
	buttonSprite.setScale(x / tmpRect.width, y / tmpRect.height);
}


