#pragma once
#ifndef EARTH_H
#define EARTH_H
#include <SFML/Graphics.hpp>
#include "Triangle.h"
#include "circle.h"
class Earth : public sf::Drawable
{
private:
	sf::Sprite EarthSprite;
	sf::Texture EarthTex;
	sf::Vector2f pos;
	std::vector<Circles> circle;
	float radius;
public:
	Earth();
	~Earth();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void setPos(float x, float y);
	void update(sf::Mouse &mouse, sf::Window &window);
	sf::Vector3f circlerxy();//radien and x and y cordinates.
};


#endif