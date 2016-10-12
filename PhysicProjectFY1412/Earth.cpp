#include "Earth.h"

Earth::Earth()
{
	EarthTex.loadFromFile("Textures\\game\\jorden\\jorden.png");
	EarthSprite.setTexture(EarthTex);
	float scale = 0.5;
	EarthSprite.scale(scale, scale);
	radius = EarthSprite.getLocalBounds().width/2;
	EarthSprite.setOrigin(radius, radius);
	pos = sf::Vector2f(920, 540);
	EarthSprite.setPosition(pos);

	//circlecreation
	circle = std::vector<Circles>(0);
	Circles circle1 = Circles(radius, 0, 0);
	circle.push_back(circle1);
	circle[0].scale(sf::Vector2f(scale, scale));
	circle[0].setorigin(sf::Vector2f(radius, radius));
	circle[0].setpoisiton(pos);


}

Earth::~Earth()
{

}

void Earth::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(EarthSprite);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		target.draw(circle[0]);
	}
}

void Earth::setPos(float x, float y)
{

}

void Earth::update(sf::Mouse & mouse, sf::Window & window)
{

}

sf::Vector3f Earth::circlerxy()
{
	

	return sf::Vector3f(920, 540, radius*0.425);
}
