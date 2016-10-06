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

void StartButton::onClick() const
{
	std::cout << "Start Button Pressed! " << std::endl;
}
