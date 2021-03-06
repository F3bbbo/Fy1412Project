#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML\Graphics.hpp>
#include <string>
#include <sstream>
#include <iomanip>

sf::Vector2f makeWorldPos(sf::Vector2f &screenPos);

sf::Vector2f makeScreenPos(sf::Vector2f &worldPos);

float length(sf::Vector2f &vec);

sf::Vector2f normalize(sf::Vector2f &vec);

sf::Vector2f multiply(sf::Vector2f &vec,double num);

std::string toString(float num, int dec);

float dotProduct(sf::Vector2f vec1, sf::Vector2f vec2);


#endif
