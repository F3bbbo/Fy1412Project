#ifndef ROTATIONBUTTON_H
#define ROTATIONBUTTON_H
#include <string>
#include "Button.h"

class RotationButton : public Button
{
private:
	RotationButton();
	virtual void onClick(Game &game)const;
	virtual void onPress(Game &game)const;
	float clickRot;
	float pressRot;
public:
	RotationButton(std::string textureFile, float rotation);
	~RotationButton();
};


#endif

