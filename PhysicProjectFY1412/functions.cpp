#include "functions.h"

#define SCREENTOWORLDTRANS 6371200.0f / 449.0f 
#define WORLDTOSCREENTRANS 449.0f / 6371200.0f


sf::Vector2f makeWorldPos(sf::Vector2f & screenPos)
{
	return screenPos * SCREENTOWORLDTRANS;
}

sf::Vector2f makeScreenPos(sf::Vector2f & worldPos)
{
	return worldPos * WORLDTOSCREENTRANS;
}

float length(sf::Vector2f & vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

sf::Vector2f normalize(sf::Vector2f & vec)
{
	return vec * 1.0f/length(vec);
}
