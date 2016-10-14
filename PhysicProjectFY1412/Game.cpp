#include "Game.h"
#include <sstream>

Game::Game()
{
	dt = 0;
}

Game::~Game()
{

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rocket);
	target.draw(earth);

}
void Game::Update(sf::RenderWindow & window, sf::Mouse &mouse)
{
	dt = clock.restart().asSeconds();
	if (dt > 0.2f)
	{
		dt = 0.000001f;
	}
	rocket.update(mouse, window, earth, 5 * dt);
	earth.update(mouse, window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		int Number = mouse.getPosition(window).x;
	string String = to_string(Number);
	//		string String = static_cast<ostringstream*>(&(ostringstream() << Number))->str();
		cout << "xvalue " << String << endl;
		Number = mouse.getPosition(window).y;
		String = to_string(Number);
		cout << "yvalue " << String << endl;
	}
	if (true == rocket.colision(earth.circlerxy()))
		cout << "works" << endl;

//	circle[0].setplacex(376);
//	circle[0].setplacey(322);

//	if (true == collisioncheckbetweencirclesandtriangle(circle[0].getplacex(), circle[0].getplacey(), circle[0].getradius(), Triangle[0].getpoint1(), Triangle[0].getpoint2(), Triangle[0].getpoint3(),Triangle[0].getside1normal(),Triangle[0].getside2normal(),Triangle[0].getside3normal()))
//		cout << "woorks" << endl;
/*	if (true == collisioncheckbetweencircles(circle[0].getplacex(), circle[0].getplacey(), circle[0].getradius(), circle[1].getplacex(), circle[1].getplacey(), circle[1].getradius()))
		
*/
	

}

void Game::rocketSpin(int degree)
{
	rocket.rotate(degree);
}

void Game::rocketSpin(float scale)
{
	rocket.rotate(scale * dt);
}
