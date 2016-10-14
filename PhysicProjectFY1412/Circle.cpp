#include "circle.h"

Circles::Circles(int radius, int placex, int placey)
{
	this->radius = radius;
	this->placex = placex;
	this->placey = placey;
	circle.setRadius(radius);
	circle.setPosition(sf::Vector2f(placex, placey));
}

Circles::~Circles() {}
void Circles::setpoisiton(sf::Vector2f position)
{
	circle.setPosition(position);
}
void Circles::setorigin(sf::Vector2f Origin)
{
	circle.setOrigin(Origin);
}
void Circles::scale(sf::Vector2f scale)
{
	circle.setScale(scale);
}
;
void Circles::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(circle);
}
void Circles::Update(float dt)
{

}

void Circles::SetFillColor(sf::Color farg)
{
	circle.setFillColor(farg);
}

float Circles::getradius()
{

	return radius;
}

int Circles::getplacex()
{
	return placex;
}

int Circles::getplacey()
{
	return placey;
}

void Circles::setplacex(int placex)
{
	this -> placex = placex;
	circle.setPosition(sf::Vector2f(placex, placey));
}

void Circles::setplacey(int placey)
{
	this->placey = placey;
	circle.setPosition(sf::Vector2f(placex, placey));
}

void Circles::setradius(float radius)
{
	this->radius = radius;
	circle.setRadius(radius);
}

void Circles::settexture(sf::Texture *texturee)
{
	circle.setTexture(texturee);
}



Circles::Circles() {};