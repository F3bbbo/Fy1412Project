#pragma once
#ifndef COLLISION_H
#define COLLISION_H
#include <iostream>
#include <SFML/Graphics.hpp>



bool collisioncheckbetweencircles(float x1, float y1, float radius1, float x2, float y2, float radius2);

bool collisioncheckbetweencirclesandtriangle(float x1, float y1, float radius1, sf::Vector2f trianglepoint1, sf::Vector2f trianglepoint2, sf::Vector2f trianglepoint3, sf::Vector2f, sf::Vector2f, sf::Vector2f);
bool collisioncheckbetweencircleandsquare(float x1, float y1, float radius1, sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3, sf::Vector2f point4);









#endif // ! Collision