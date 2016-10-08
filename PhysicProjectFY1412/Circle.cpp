#include "circle.h"

Circles::Circles(int radius, int placex, int placey)
{
	this->radius = radius;
	this->placex = placex;
	this->placey = placey;
	circle.setRadius(radius);
	circle.setPosition(sf::Vector2f(placex, placey));
}

Circles::~Circles() {};
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

int Circles::getradius()
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

void Circles::setradius(int radius)
{
	this->radius = radius;
	circle.setRadius(radius);
}



Circles::Circles() {};