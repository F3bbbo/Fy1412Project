#include "StartButton.h"

StartButton::StartButton()
	:Button()
{

}

StartButton::StartButton(std::string spriteFileName)
	:Button(spriteFileName)
{

}


StartButton::~StartButton()
{

}

void StartButton::onClick(Game &game) const
{
	game.rocketThrust(0.0f);
}

void StartButton::onPress(Game &game) const
{
	game.rocketThrust(1.0f);
}
