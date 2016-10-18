#include "Earth.h"

#define G 6.674e-11

Earth::Earth()
{
	EarthTex.loadFromFile("Textures\\game\\jorden\\jorden.png");
	EarthSprite.setTexture(EarthTex);
	scale = 0.5;
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

	std::cout << EarthSprite.getGlobalBounds().width << std::endl;

	mass = 5.972e24;
	worldPos = makeWorldPos(pos);
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

float Earth::gForce(float mass, float radius)
{
	return G * this->mass * mass / (radius * radius);
}
float Earth::acceleration(float radius)
{
	return  G * this->mass / (radius * radius); //G*(M/R^2)=G
}

sf::Vector2f Earth::getWorldPos()
{
	return worldPos;
}

void Earth::update(sf::Mouse & mouse, sf::Window & window)
{

}

sf::Vector3f Earth::circlerxy()
{
	

	return sf::Vector3f(/*920, 540*/pos.x, pos.y, radius*scale/*0.417*/);
}
