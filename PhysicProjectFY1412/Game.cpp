#include "Game.h"


Game::Game()
{
	button = new StartButton("Textures\\gui\\StartButton.png");
	button->setSize(100, 20);
//	circle = std::vector<Circles>(0);
//	Circles circle1 = Circles(20, 4, 5);
//	circle1.SetFillColor(sf::Color::Red);
//	circle.push_back(circle1);
//	Circles circle2 = Circles(60, 100, 200);
//	circle2.SetFillColor(sf::Color::Blue);
//	circle.push_back(circle2);

	//	circle = new Circles(100, 20, 30);

	//	circle = new Circles[50];
}

Game::~Game()
{
	delete button;

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*button);
//	for (int i = 0;i<circle.size();i++)
//		target.draw(circle[i]);
}
void Game::Update(float dt, sf::RenderWindow & window)
{
	button->update(mouse.getPosition(window), mouse.isButtonPressed(sf::Mouse::Button::Left));

//	circle[1].Update(dt);
}
