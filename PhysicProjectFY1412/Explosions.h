#ifndef EXPLOSIONS_H
#define EXPLOSIONS_H
#pragma once
#include <iostream>
#include "circle.h"
#include <SFML/Graphics.hpp>
#include "functions.h"
class explosion : public sf::Drawable
{
private:
	Circles *circle;
	float P, a, B, Y, G, z; //P = overpressure, a,b,y,g variables for formle, and z is so you can create a b y g. 
	float d, m; //d= how long to check the over pressure, m = the mass of the explosives.
	float Pmax, procentpart;
	float t, k, pk, p2;//for the airdamping. 
	void airdamping();
	float time,howlongwillitrun;
	float scale;
	sf::Clock clock;
	int count;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	sf::Texture ExplosionsTex[6];
public:
	explosion();
	~explosion();
	void zcalculation();
	void Pressurecalculation();
	void acalculation();
	void Bcalculcation();
	void Ycalculation();
	void Gcalculation();
	void setd(float d);
	void setm(float m);
	float getP();
	bool done();
	void update(sf::Vector2f, sf::Vector2f,float);
	void circleradiusexpansion(float dt);
	void resetfunction();
	Circles circleretriver();
};

#endif