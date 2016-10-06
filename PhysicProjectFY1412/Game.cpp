#include "Game.h"


Game::Game()
{

}

Game::~Game()
{

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(rocket);
}
void Game::Update(sf::RenderWindow & window)
{
	dt = clock.getElapsedTime().asSeconds();
}

void Game::rocketSpin(float degree)
{
	rocket.rotate(degree);
}

void Game::rocketSpin(int scale)
{
	rocket.rotate(scale * dt);
}
