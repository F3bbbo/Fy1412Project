#ifndef ROCKET_H
#define ROCKET_H
#include <SFML/Graphics.hpp>

class Rocket : public sf::Drawable
{
private:
	sf::Sprite rocketSprite;
	sf::Texture rocketTex;
	sf::Sprite fireSprite;
	sf::Texture fireTex;
	sf::Vector2f pos;
	bool exhausting;
public:
	Rocket();
	~Rocket();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void setPos(float x, float y);
	void rotate(float degree);
};


#endif