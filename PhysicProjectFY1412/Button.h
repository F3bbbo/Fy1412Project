#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Game.h"

class Button : public sf::Drawable
{
private:
	bool clickedLastFrame = false;
	sf::Sprite buttonSprite;
	sf::Texture buttonTexture;
	virtual void onClick() const =0;
public:
	Button();
	Button(std::string spriteFileName);
	~Button();
	void update(Game &game, sf::Vector2i mousePos, bool buttonPressed);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void setPosition(float x, float y);
	void setSize(float x, float y);
};

#endif
