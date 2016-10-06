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
