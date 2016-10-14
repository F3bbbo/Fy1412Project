#include "Explosions.h"

void explosion::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
}

explosion::explosion()
{
	P = 0;
	B = 0;
	a = 0;Y = 0;G = 0; z = 0;
}

explosion::~explosion()
{
}

void explosion::zcalculation()
{
	z = (d / cbrt(m));
}

void explosion::Pressurecalculation()
{
	P = (8.08 * 100000000 * a) / (sqrt(B*Y*G));
}

void explosion::acalculation()
{
	a = 1 + pow((z / 4.5), 2);
}

void explosion::Bcalculcation()
{
	B = 1 + pow((float)(z / 4.048), 2);
}

void explosion::Ycalculation()
{
	Y = 1 + pow((float)(z / 0.32), 2);
}

void explosion::Gcalculation()
{
	G = 1 + pow((float)(z / 1.35), 2);
}

void explosion::setd(float d)
{
	this->d = d;
}

void explosion::setm(float m)
{
	this->m = m * 1000000;
}

void explosion::update()
{
}
