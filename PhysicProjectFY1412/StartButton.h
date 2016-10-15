#ifndef STARTBUTTON_H
#define STARTBUTTON_H
#include "Button.h"
#include <string>

class StartButton : public Button
{
private:
	virtual void onClick(Game &game) const;
	virtual void onPress(Game &game) const;
public:
	StartButton();
	StartButton(std::string spriteFileName);
	~StartButton();
};


#endif
