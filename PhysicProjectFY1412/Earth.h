#pragma once
#ifndef EARTH_H
#define EARTH_H
#include <SFML/Graphics.hpp>
#include "Triangle.h"
#include "circle.h"
#include "functions.h"

class Earth : public sf::Drawable
{
private:
	sf::Sprite EarthSprite;
	sf::Texture EarthTex;
	sf::Vector2f pos;
	std::vector<Circles> circle;
	float radius;
	float mass;
	sf::Vector2f worldPos;
public:
	Earth();
	~Earth();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void setPos(float x, float y);
	float gForce(float mass, float radius);
	float acceleration(float radius);
	sf::Vector2f getWorldPos();
	void update(sf::Mouse &mouse, sf::Window &window);
	sf::Vector3f circlerxy();//radien and x and y cordinates.
};


#endif