#ifndef SQUARE_H
#define SQUARE_H
#pragma once
#include <iostream>
#include<SFML/Graphics.hpp>


class Square : public sf::Drawable
{
private:
	sf::RectangleShape square;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2f point1/*topleft*/, point2/*topright*/, point3/*bottomright*/, point4/*bottomleft*/;
public:
	void Update(float dt);
	Square();
	Square(float length, float height);
	void setrotatesquare(float);
	void rotate(float);
	void setpoisiton(sf::Vector2f);
	void setorigin(sf::Vector2f);
	void scale(sf::Vector2f scale);
	sf::Vector2f getpoint1();
	sf::Vector2f getpoint2();
	sf::Vector2f getpoint3();
	sf::Vector2f getpoint4();
	void setpoint1(sf::Vector2f point1);
	void setpoint2(sf::Vector2f point2);
	void setpoint3(sf::Vector2f point3);
	void setpoint4(sf::Vector2f point4);
	void SquareUpdate();
};







#endif