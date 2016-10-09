#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Triangles
{
private:
	sf::Vector2f trianglepoint1, trianglepoint2, trianglepoint3, side1normal, side2normal, side3normal;
public:
	void Update(float dt);
	Triangles();
	Triangles(sf::Vector2f trianglepoint1, sf::Vector2f trianglepoint2, sf::Vector2f trianglepoint3, sf::Vector2f side1normal, sf::Vector2f side2normal, sf::Vector2f side3normal);
	~Triangles();
	//	void color(sf::Color::Red);
	sf::Vector2f getpoint1();
	sf::Vector2f getpoint2();
	sf::Vector2f getpoint3();
	sf::Vector2f getside1normal();
	sf::Vector2f getside2normal();
	sf::Vector2f getside3normal();


	void settrianglepoint1(sf::Vector2f trianglepoint1);
	void settrianglepoint2(sf::Vector2f trianglepoint2);
	void settrianglepoint3(sf::Vector2f trianglepoint3);
	void setside1normal(sf::Vector2f side1normal);
	void setside2normal(sf::Vector2f side2normal);
	void setside3normal(sf::Vector2f side3normal);

};





#endif