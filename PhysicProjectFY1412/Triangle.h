#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Triangles : public sf::Drawable
{
private:
	sf::CircleShape triangle;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Vector2f trianglepoint1, trianglepoint2, trianglepoint3, side1normal, side2normal, side3normal;
public:
	void Update(float dt);
	Triangles();
//	Triangles(sf::Vector2f trianglepoint1, sf::Vector2f trianglepoint2, sf::Vector2f trianglepoint3, sf::Vector2f side1normal, sf::Vector2f side2normal, sf::Vector2f side3normal);
	Triangles(float);
	~Triangles();
	void Triangleuppdate();
	void setrotate(float);
	//	void color(sf::Color::Red);
	sf::Vector2f getpoint1();
	sf::Vector2f getpoint2();
	sf::Vector2f getpoint3();
	sf::Vector2f getside1normal();
	sf::Vector2f getside2normal();
	sf::Vector2f getside3normal();
	void movetolocalspace(sf::Vector2f centrumrotation);
	void scale(sf::Vector2f scale);
	void movetoworldspace(sf::Vector2f centrumrotation);
	void movepos(sf::Vector2f rocketpos);
	void setpoisiton(sf::Vector2f);
	void setorigin(sf::Vector2f);
	void settrianglepoint1(sf::Vector2f trianglepoint1);
	void settrianglepoint2(sf::Vector2f trianglepoint2);
	void settrianglepoint3(sf::Vector2f trianglepoint3);
	void setside1normal(sf::Vector2f side1normal);
	void setside2normal(sf::Vector2f side2normal);
	float trianglegetwith();
	void setside3normal(sf::Vector2f side3normal);
	void rotatetriangle(float degree);
	void movetolocalspaceandrotatetriangle(sf::Vector2f rocketpos , float degree);
};





#endif