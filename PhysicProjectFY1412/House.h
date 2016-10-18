#ifndef HOUSE_H
#define HOUSE_H
#pragma once
#include <iostream>
#include "Square.h"
#include <SFML/Graphics.hpp>
#include "functions.h"
class Houses : public sf::Drawable
{
private:
	Square square;
	sf::Vector2f positon;
	sf::Vector2f scale;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::Texture Texture[4];
	sf::Sprite sprite;
public:
	Houses();
	void changesprite(float P);
	~Houses();
	void housereset();
	Square returnsquare();
};



#endif