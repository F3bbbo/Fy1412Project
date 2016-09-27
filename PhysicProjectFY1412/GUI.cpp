#include "GUI.h"

GUI::GUI()
{

}

GUI::~GUI()
{
	if (buttons != nullptr)
	{
		delete[] buttons;
	}
}

void GUI::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

}
