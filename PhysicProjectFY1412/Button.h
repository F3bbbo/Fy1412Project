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
	virtual void onClick(Game &game) const =0;
	virtual void onPress(Game &game) const;
public:
	Button();
	Button(std::string spriteFileName);
	virtual ~Button();
	void update(Game &game, sf::Vector2i mousePos, bool buttonPressed);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void setPosition(float x, float y);
	void setSize(float x, float y);
	void setScale(float x, float y);
	void scale(float x, float y);
	void flipButton(bool up, bool side);
};

#endif
