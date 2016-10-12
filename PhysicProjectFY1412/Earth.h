#pragma once
#ifndef EARTH_H
#define EARTH_H
#include <SFML/Graphics.hpp>
#include "Triangle.h"
#include "Collision.h"
#include "circle.h"
class Earth : public sf::Drawable
{
private:
	sf::Sprite EarthSprite;
	sf::Texture EarthTex;
	sf::Vector2f pos;
public:
	Earth();
	~Earth();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void setPos(float x, float y);
	void update(sf::Mouse &mouse, sf::Window &window);
};


#endif