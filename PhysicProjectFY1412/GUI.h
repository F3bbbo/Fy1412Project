#ifndef GUI_H
#define GUI_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Game.h"

class GUI : public sf::Drawable
{
private:
	Button **buttons;
	int nrOfButtons;
public:
	GUI();
	~GUI();
	void update(Game &game, sf::Mouse &mouse, sf::Window &window);
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const;
};



#endif
