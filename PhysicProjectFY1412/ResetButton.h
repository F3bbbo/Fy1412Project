#ifndef RESETBUTTON_H
#define RESETBUTTON_H
#include "Button.h"


class ResetButton : public Button
{
private:
	virtual void onClick(Game &game)const;
public:
	ResetButton();
	~ResetButton();
	
};


#endif
