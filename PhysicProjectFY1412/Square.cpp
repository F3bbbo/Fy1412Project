#include "Square.h"

void Square::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(square);
}

void Square::Update(float dt)
{

}

Square::Square()
{
	square.setSize(sf::Vector2f(120, 30));
	square.setPosition(sf::Vector2f(120, 40));

}

Square::Square(float length, float height)
{
	square.setSize(sf::Vector2f(length, height));
	square.setPosition(sf::Vector2f(120, 40));
}

void Square::setrotatesquare(float degree)
{
	square.setRotation(degree);
}

void Square::rotate(float degree)
{
	square.rotate(degree);
}

void Square::setpoisiton(sf::Vector2f position)
{
	square.setPosition(position);
}

void Square::setorigin(sf::Vector2f origin)
{
	square.setOrigin(origin);
}

void Square::scale(sf::Vector2f scale)
{
	square.setScale(scale);
}

sf::Vector2f Square::getpoint1()
{
	return point1;
}

sf::Vector2f Square::getpoint2()
{
	return point2;
}

sf::Vector2f Square::getpoint3()
{
	return point3;
}

sf::Vector2f Square::getpoint4()
{
	return point4;
}

void Square::setpoint1(sf::Vector2f point1)
{
	this->point1 = point1;
}

void Square::setpoint2(sf::Vector2f point2)
{
	this->point2 = point2;
}

void Square::setpoint3(sf::Vector2f point3)
{
	this->point3 = point3;
}

void Square::setpoint4(sf::Vector2f point4)
{
	this->point4 = point4;
}

void Square::SquareUpdate()
{


	float kordinatochbred[4];
	kordinatochbred[0] = square.getGlobalBounds().left; //left vänstrapunkten högst upp på fyrkantens x kordinat. och top är des y kordinat. width är bredden på hela och height är höjden.
	kordinatochbred[1] = square.getGlobalBounds().top;
	kordinatochbred[2] = square.getGlobalBounds().width;
	kordinatochbred[3] = square.getGlobalBounds().height;
	//	triangle.setRadius(140);
	this->point1 = sf::Vector2f(kordinatochbred[0], kordinatochbred[1]);
	this->point2 = sf::Vector2f(kordinatochbred[0] + kordinatochbred[2], kordinatochbred[1]);
	this->point3 = sf::Vector2f(kordinatochbred[0] + kordinatochbred[2], kordinatochbred[1] + kordinatochbred[3]);
	this->point4 = sf::Vector2f(kordinatochbred[0], kordinatochbred[1] + kordinatochbred[3]);
};
