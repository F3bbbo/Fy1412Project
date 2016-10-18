#include "Explosions.h"
#define WORLDTOSCREENTRANS 224.5f / 6371200.0f
#define SCREENTOWORLDTRANS 6371200.0f / 224.5f 
void explosion::airdamping()
{
	t = 40000000 / 8000; //40*10^6m and 8*10^3m 
	k = (log(pk / p2)) / t;
	P=P - P*exp(-k*t);
	
}
void explosion::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*circle);
}

explosion::explosion()
{
	circle = new Circles(0, 0, 0);
	ExplosionsTex[0].loadFromFile("Textures\\game\\Explosions\\deanExplosion_stage1.png");
	ExplosionsTex[1].loadFromFile("Textures\\game\\Explosions\\deanExplosion_stage2.png");
	ExplosionsTex[2].loadFromFile("Textures\\game\\Explosions\\deanExplosion_stage3.png");
	ExplosionsTex[3].loadFromFile("Textures\\game\\Explosions\\deanSmoke_stage1.png");
	ExplosionsTex[4].loadFromFile("Textures\\game\\Explosions\\deanSmoke_stage2.png");
	ExplosionsTex[5].loadFromFile("Textures\\game\\Explosions\\deanSmoke_stage3.png");
	circle->settexture(&ExplosionsTex[0]);
	P = 1;
	B = 0;
	a = 0;Y = 0;G = 0; z = 0;
	circle->setradius(0);
	m = 2*1000000;
	pk = 1000;
	p2 = 1;
}

explosion::~explosion()
{
	delete circle;
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
	this->m = m * 10000000;
}

float explosion::getP()
{
	return P;
}


void explosion::circleradiusexpansion(float dt)
{
	if (P <= 1900)
	{

	}
	else
	circle->setradius(circle->getradius() + 8000 * WORLDTOSCREENTRANS*dt);
}
void explosion::resetfunction()
{
	circle->setradius(0);
}
Circles explosion::circleretriver()
{
	return circle[0];
}
void explosion::update(sf::Vector2f origin, sf::Vector2f position,float dt)
{
	circle->setorigin(sf::Vector2f(circle->getradius()+ origin.x, circle->getradius()+ origin.y));
//	circle->setorigin(origin);
	circle->setpoisiton(position);
	setd(SCREENTOWORLDTRANS*circle->getradius());
	zcalculation();
	acalculation();
	Bcalculcation();
	Ycalculation();
	Gcalculation();
	Pressurecalculation();
	airdamping();
	if(P>60000 && P<70000)
		circle->settexture(&ExplosionsTex[1]);
	if (P>40000 && P<60000)
		circle->settexture(&ExplosionsTex[2]);
	if (P>20000 && P<40000)
		circle->settexture(&ExplosionsTex[3]);
	if (P>10000 && P<20000)
		circle->settexture(&ExplosionsTex[4]);
	if (P>2000 && P<10000)
		circle->settexture(&ExplosionsTex[5]);



	circleradiusexpansion(dt);


}
