#pragma once
#ifndef COLLISION_H
#define COLLISION_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "functions.h"
#include "Square.h"
#include "Triangle.h"

bool collisioncheckbetweencircles(float x1, float y1, float radius1, float x2, float y2, float radius2);

bool collisioncheckbetweencirclesandtriangle(float x1, float y1, float radius1, sf::Vector2f trianglepoint1, sf::Vector2f trianglepoint2, sf::Vector2f trianglepoint3, sf::Vector2f, sf::Vector2f, sf::Vector2f);
bool collisioncheckbetweencircleandsquare(float x1, float y1, float radius1, sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3, sf::Vector2f point4);

bool collisionLineLine(sf::Vector2f line1P1, sf::Vector2f line1P2, sf::Vector2f line2P1, sf::Vector2f line2P2);
bool collisionsquareandtriangleintersection(Triangles triangle, Square square);






#endif // ! Collision