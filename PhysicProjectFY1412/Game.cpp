#include "Game.h"
#include <sstream>
#include <iostream>
Game::Game()
{
	dt = 0;
	colision = false;
	running = false;
	explosioncolideswithhouse = false;
	extradt = 0;
	textFont.loadFromFile("Textures\\fonts\\STENCIL.TTF");
	startText.setFont(textFont);
	startText.setPosition(500, 20);
	startText.setCharacterSize(40);
	startText.setStyle(sf::Text::Bold);
	startText.setColor(sf::Color::White);
	startText.setString("Hit the house with the rocket.");
	endText.setFont(textFont);
	endText.setPosition(1000, 100);
	endText.setCharacterSize(50);
	endText.setStyle(sf::Text::Bold);
	endText.setColor(sf::Color::White);
}

Game::~Game()
{

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(earth);
	target.draw(house);
	target.draw(rocket);
	target.draw(startText);
	target.draw(endText);

}
void Game::Update(sf::RenderWindow & window, sf::Mouse &mouse)
{
	dt = clock.restart().asSeconds();
	
	if (dt > 0.01f)
	{
		dt = 0.01f;
	}

	if (running)
	{
	//	extradt = dt + extradt;
	//	if (extradt >= 2)
	//	{			 
			colision = rocket.colision(earth.circlerxy(),house.returnsquare());
			if (true == rocket.colisionexplosionandhouse(house.returnsquare()))
				explosioncolideswithhouse = true;
	//	}
		rocket.update(mouse, window, earth, dt,colision, explosioncolideswithhouse);
		house.changesprite(rocket.returnp());
	}

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

void Game::rocketThrust(float thrust)
{
	running = true;
	rocket.setThrust(thrust);
}

void Game::reset()
{
	running = false;
	rocket.reset();
}

void Game::rocketSpin(float scale)
{
	rocket.rotate(scale * dt);
}
