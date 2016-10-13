#include "functions.h"

#define SCREENTOWORLDTRANS 6371200.0f / 449.0f  


sf::Vector2f getWorldPos(sf::Vector2f & screenPos)
{
	return screenPos * SCREENTOWORLDTRANS;
}

sf::Vector2f getScreenPos(sf::Vector2f & worldPos)
{
	return worldPos * 1.0f / SCREENTOWORLDTRANS;
}

float length(sf::Vector2f & vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

sf::Vector2f normalize(sf::Vector2f & vec)
{
	return vec * 1.0f/length(vec);
}
