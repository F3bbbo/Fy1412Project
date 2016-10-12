#pragma once
#ifndef KVADRAT_H
#define KVADRAT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Kvadrat : public sf::Drawable
{
private:
	
	sf::RectangleShape kvadrat;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2f trianglepoint1, trianglepoint2, trianglepoint3, side1normal, side2normal, side3normal;
public:
	void Update(float dt);
	Kvadrat();
	//	Triangles(sf::Vector2f trianglepoint1, sf::Vector2f trianglepoint2, sf::Vector2f trianglepoint3, sf::Vector2f side1normal, sf::Vector2f side2normal, sf::Vector2f side3normal);
	Kvadrat(float);
	~Kvadrat();
	void Kvadratuppdate();


}

#endif