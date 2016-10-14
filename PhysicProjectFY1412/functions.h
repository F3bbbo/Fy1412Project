#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML\Graphics.hpp>

sf::Vector2f makeWorldPos(sf::Vector2f &screenPos);

sf::Vector2f makeScreenPos(sf::Vector2f &worldPos);

float length(sf::Vector2f &vec);

sf::Vector2f normalize(sf::Vector2f &vec);

sf::Vector2f multiply(sf::Vector2f &vec,double num);


#endif
