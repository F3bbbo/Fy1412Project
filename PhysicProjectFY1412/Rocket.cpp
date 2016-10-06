#include "Rocket.h"

Rocket::Rocket()
{
	//Load textures
	rocketTex.loadFromFile("Textures\\game\\rocket\\Rocket.png");
	fireTex.loadFromFile("Textures\\game\\rocket\\Fire.png");
	//Set textures
	rocketSprite.setTexture(rocketTex);
	fireSprite.setTexture(fireTex);
	//Scaling
	float scale = 0.5;
	rocketSprite.scale(scale, scale);
	fireSprite.scale(scale, scale);

	//Sets origin of rocket and fire to the same point
	float halfRocketWidth = rocketSprite.getLocalBounds().width / 2;
	float halfRocketHeight = rocketSprite.getLocalBounds().height / 2;
	float fireHeight = fireSprite.getLocalBounds().height;
	rocketSprite.setOrigin(halfRocketWidth, halfRocketHeight);
	fireSprite.setOrigin(halfRocketWidth, -halfRocketHeight + 0.02 * halfRocketHeight);
	//Set the initial position of the rocket
	pos = sf::Vector2f(400, 400);
	rocketSprite.setPosition(pos);
	fireSprite.setPosition(pos);
	exhausting = true;
}

Rocket::~Rocket()
{

}

void Rocket::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (exhausting)
	{
		target.draw(fireSprite);
	}
	target.draw(rocketSprite);
}

void Rocket::setPos(float x, float y)
{
	rocketSprite.setPosition(x, y);
	fireSprite.setPosition(x, y);
}

void Rocket::rotate(float degree)
{
	rocketSprite.rotate(degree);
	fireSprite.rotate(degree);
}
