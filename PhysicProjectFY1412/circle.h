#ifndef CIRCLE_H
#define CIRCLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Circles : public sf::Drawable
{
private:
	sf::CircleShape circle;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	int radius;
	int placex;
	int placey;

public:
	void Update(float dt);
	Circles();
	Circles(int, int, int);
	~Circles();
	//	void color(sf::Color::Red);
	void SetFillColor(sf::Color color);
	int getradius();
	int getplacex();
	int getplacey();
	void setplacex(int placex);
	void setplacey(int placey);
	void setradius(int radius);
};





#endif