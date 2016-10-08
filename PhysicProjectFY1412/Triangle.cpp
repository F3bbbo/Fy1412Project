#include "Triangle.h"


void Triangles::Update(float dt)
{
}

Triangles::Triangles()
{
}

Triangles::Triangles(sf::Vector2f trianglepoint1, sf::Vector2f trianglepoint2, sf::Vector2f trianglepoint3, sf::Vector2f side1normal, sf::Vector2f side2normal, sf::Vector2f side3normal)
{
	this->trianglepoint1 = trianglepoint1;
	this->trianglepoint2 = trianglepoint2;
	this->trianglepoint3 = trianglepoint3;
	this->side1normal = side1normal;
	this->side2normal = side2normal;
	this->side3normal = side3normal;
}

Triangles::~Triangles()
{

}



sf::Vector2f Triangles::getpoint1()
{
	return this->trianglepoint1;
}

sf::Vector2f Triangles::getpoint2()
{
	return this->trianglepoint2;
}

sf::Vector2f Triangles::getpoint3()
{
	return this->trianglepoint3;
}

sf::Vector2f Triangles::getside1normal()
{
	return side1normal;
}

sf::Vector2f Triangles::getside2normal()
{
	return side2normal;
}

sf::Vector2f Triangles::getside3normal()
{
	return side3normal;
}

void Triangles::settrianglepoint1(sf::Vector2f trianglepoint1)
{
	this->trianglepoint1 = trianglepoint1;
}

void Triangles::settrianglepoint2(sf::Vector2f trianglepoint2)
{
	this->trianglepoint2 = trianglepoint2;
}

void Triangles::settrianglepoint3(sf::Vector2f trianglepoint3)
{
	this->trianglepoint3 = trianglepoint3;
}

void Triangles::setside1normal(sf::Vector2f side1normal)
{
	this->side1normal = side1normal;

}

void Triangles::setside2normal(sf::Vector2f side2normal)
{
	this->side2normal = side2normal;

}

void Triangles::setside3normal(sf::Vector2f side3normal)
{
	this->side3normal = side3normal;
}
