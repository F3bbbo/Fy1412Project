#include "Button.h"

void Button::onPress(Game & game) const
{

}

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
		//Check if clicking the button
		if (buttonPressed)
		{
			clickedLastFrame = true;
			onPress(game);
		}
		else if (clickedLastFrame)
		{
			onClick(game);
			clickedLastFrame = false;
		}
		//Change colour of button if it is pressed down
		if (clickedLastFrame)
			buttonSprite.setColor(sf::Color(0, 255, 0, 255));
		else
			buttonSprite.setColor(sf::Color(255, 255, 255, 255));

	}
	else
	{
		if(clickedLastFrame)
			buttonSprite.setColor(sf::Color(255, 255, 255, 255));
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

void Button::setScale(float x, float y)
{
	buttonSprite.setScale(x, y);
}

void Button::scale(float x, float y)
{
	buttonSprite.scale(x, y);
}

void Button::flipButton(bool up, bool side)
{
	sf::IntRect rect = buttonSprite.getTextureRect();
	buttonSprite.setTextureRect(sf::IntRect(rect.width, 0, -rect.width, rect.height));
}




