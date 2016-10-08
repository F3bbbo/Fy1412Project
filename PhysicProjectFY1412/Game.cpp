#include "Game.h"


Game::Game()
{
	circle = std::vector<Circles>(0);
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
	
	circle[0].setplacex(mouse.getPosition().x);
	circle[0].setplacey(mouse.getPosition().y);
//	circle[0].setradius(mouse.getPosition().y);
/*	if (true == collisioncheckbetweencircles(circle[0].getplacex(), circle[0].getplacey(), circle[0].getradius(), circle[1].getplacex(), circle[1].getplacey(), circle[1].getradius()))
		cout << "woorks" << endl;
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
