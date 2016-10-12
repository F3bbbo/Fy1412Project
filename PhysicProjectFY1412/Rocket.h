#ifndef ROCKET_H
#define ROCKET_H
#include <SFML/Graphics.hpp>
#include "Triangle.h"
#include "Collision.h"
#include "circle.h"
class Rocket : public sf::Drawable
{
private:
	sf::Sprite rocketSprite;
	sf::Texture rocketTex;
	sf::Sprite fireSprite;
	sf::Texture fireTex;
	sf::Vector2f pos;
	bool exhausting;
	std::vector<Circles> circle;
	std::vector<Triangles>Triangle;
public:
	Rocket();
	~Rocket();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void setPos(float x, float y);
	void rotate(float degree);
	bool colision(sf::Vector3f circle);
	void update(sf::Mouse &mouse, sf::Window &window);
};


#endif