#include "RotationButton.h"

RotationButton::RotationButton()
{

}

void RotationButton::onClick(Game &game) const
{
	//game.rocketSpin(clickRot);
}

void RotationButton::onPress(Game & game) const
{
	game.rocketSpin(pressRot);
}

RotationButton::RotationButton(std::string textureFile, float rotation)
	:Button(textureFile)
{
	this->clickRot = rotation;
	if (rotation <= 0)
	{
		this->flipButton(true, true);
		this->pressRot = -1;
	}
	else
	{
		this->pressRot = 1;
	}
		
}

RotationButton::~RotationButton()
{

}

