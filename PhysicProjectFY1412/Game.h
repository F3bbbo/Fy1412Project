#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Rocket.h"
#include <string>
#include <vector>
#include "circle.h"
#include "Collision.h"
#include "Triangle.h"
using namespace std;
class Game : public sf::Drawable
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Clock clock;
	float dt;
	Rocket rocket;
	

public:
	Game();
	~Game();
	void Update(sf::RenderWindow & window, sf::Mouse &mouse);
	void rocketSpin(float scale);
	void rocketSpin(int degree);
};










#endif GAME_H