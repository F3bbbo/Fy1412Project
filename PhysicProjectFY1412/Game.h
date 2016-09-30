#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "StartButton.h"
#include "GUI.h"
#include <string>
//#include "circle.h"
#include <vector>

using namespace std;
class Game : public sf::Drawable
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Mouse mouse;
	StartButton *button;
//	std::vector<Circles> circle;
public:
	Game();
	~Game();
	void Update(float dt, sf::RenderWindow & window);
};










#endif GAME_H