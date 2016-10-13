#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML\Graphics.hpp>

sf::Vector2f getWorldPos(sf::Vector2f &screenPos);

sf::Vector2f getScreenPos(sf::Vector2f &worldPos);

float length(sf::Vector2f &vec);

sf::Vector2f normalize(sf::Vector2f &vec);


#endif
