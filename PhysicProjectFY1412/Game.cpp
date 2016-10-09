#include "Game.h"
#include <sstream>

Game::Game()
{
	circle = std::vector<Circles>(0);
	Triangle = std::vector<Triangles>(0);
	Triangles tringle1 = Triangles(sf::Vector2f(389, 277), sf::Vector2f(360, 372), sf::Vector2f(429, 371), sf::Vector2f(0, 1), sf::Vector2f(1, 0), sf::Vector2f(-1, 0));
	Triangle.push_back(tringle1);
	Circles circle1 = Circles(20, 4, 5);
	circle.push_back(circle1);
//	circle1 = Circles(25, 6, 5);
	circle1.setplacex(6);
	circle1.setradius(25);
	circle.push_back(circle1);
}

Game::~Game()
{

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rocket);
	for(int i=0;i<2;i++)
	target.draw(circle[i]);
}
void Game::Update(sf::RenderWindow & window, sf::Mouse &mouse)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
	{
		int Number = mouse.getPosition(window).x;
		string String = to_string(Number);
		//	string String = static_cast<ostringstream*>(&(ostringstream() << Number))->str();
		cout << "xvalue " << String << endl;
		Number = mouse.getPosition(window).y;
		String = to_string(Number);
		cout << "yvalue " << String << endl;
	}
	circle[0].setplacex(mouse.getPosition(window).x);
	circle[0].setplacey(mouse.getPosition(window).y);
//	circle[0].setplacex(376);
//	circle[0].setplacey(322);

	if (true == collisioncheckbetweencirclesandtriangle(circle[0].getplacex(), circle[0].getplacey(), circle[0].getradius(), Triangle[0].getpoint1(), Triangle[0].getpoint2(), Triangle[0].getpoint3(),Triangle[0].getside1normal(),Triangle[0].getside2normal(),Triangle[0].getside3normal()))
		cout << "woorks" << endl;
/*	if (true == collisioncheckbetweencircles(circle[0].getplacex(), circle[0].getplacey(), circle[0].getradius(), circle[1].getplacex(), circle[1].getplacey(), circle[1].getradius()))
		
*/
	

	dt = clock.restart().asSeconds();
}

void Game::rocketSpin(int degree)
{
	rocket.rotate(degree);
}

void Game::rocketSpin(float scale)
{
	rocket.rotate(scale * dt);
}
