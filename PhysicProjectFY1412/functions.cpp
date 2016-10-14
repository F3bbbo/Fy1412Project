#include "functions.h"

#define SCREENTOWORLDTRANS 6371200.0f / 224.5f 
#define WORLDTOSCREENTRANS 224.5f / 6371200.0f


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

sf::Vector2f multiply(sf::Vector2f & vec, double num)
{
	return sf::Vector2f(vec.x*num, vec.y*num);
}
