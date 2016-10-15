#include "ResetButton.h"

void ResetButton::onClick(Game & game) const
{
	game.reset();
}

ResetButton::ResetButton()
	:Button("Textures\\gui\\ResetButton.png")
{

}

ResetButton::~ResetButton()
{
}
