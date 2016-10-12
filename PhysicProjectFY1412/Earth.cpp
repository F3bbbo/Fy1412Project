#include "Earth.h"

Earth::Earth()
{
	EarthTex.loadFromFile("Textures\\game\\jorden\\jorden.png");
	EarthSprite.setTexture(EarthTex);
	float scale = 1;
	EarthSprite.scale(scale, scale);
	float radius = EarthSprite.getLocalBounds().width/2;
	EarthSprite.setOrigin(radius, radius);
	pos = sf::Vector2f(600, 500);
	EarthSprite.setPosition(pos);
}

Earth::~Earth()
{

}

void Earth::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(EarthSprite);
}

void Earth::setPos(float x, float y)
{

}

void Earth::update(sf::Mouse & mouse, sf::Window & window)
{

}
