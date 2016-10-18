#include "House.h"

void Houses::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		target.draw(square);
	}
}

Houses::Houses()
{
	Texture[1].loadFromFile("Textures\\game\\huset\\housebrokenglass.png");
	Texture[3].loadFromFile("Textures\\game\\huset\\housebrokenglassandcrashed.png");
	Texture[2].loadFromFile("Textures\\game\\huset\\housebrokenglassandhalfcrashed.png");
	Texture[0].loadFromFile("Textures\\game\\huset\\housewithglas.png");
	sprite.setTexture(Texture[0]);
	square= Square(200, 200);
	positon = sf::Vector2f(930, 449+300+60);
	scale = sf::Vector2f(0.5, 0.5);

	sprite.scale(scale);
	square.scale(scale);

	sprite.setOrigin(sf::Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height));
	
	square.setorigin(sf::Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height));
	
	sprite.setPosition(positon);
	square.setpoisiton(positon);
	sprite.setRotation(180);
	square.setrotatesquare(180);
	square.SquareUpdate();

	broken = false;
}

void Houses::changesprite(float P)
{
	if (700000 <= P)
	{
		broken = true;
		sprite.setTexture(Texture[3]);
	}
	else if (1500 <= P)
	{
		sprite.setTexture(Texture[2]);
	}
	else if (0.1 <= P)
	{
		sprite.setTexture(Texture[1]);
	}

}

Houses::~Houses()
{

}

void Houses::housereset()
{
	sprite.setTexture(Texture[0]);
	broken = false;
}

bool Houses::isBroken()
{
	return broken;
}

Square Houses::returnsquare()
{
	return square;
}

