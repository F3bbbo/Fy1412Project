#include "Rocket.h"

Rocket::Rocket()
{
	//Load textures
	rocketTex.loadFromFile("Textures\\game\\rocket\\Rocket.png");
	fireTex.loadFromFile("Textures\\game\\rocket\\Fire.png");
	//Set textures
	rocketSprite.setTexture(rocketTex);
	fireSprite.setTexture(fireTex);
	//Scaling
	float scale = 0.1;//0.5;
	rocketSprite.scale(scale, scale);
	fireSprite.scale(scale, scale);

	//Sets origin of rocket and fire to the same point
	float halfRocketWidth = rocketSprite.getLocalBounds().width / 2;
	float halfRocketHeight = rocketSprite.getLocalBounds().height / 2;
	float fireHeight = fireSprite.getLocalBounds().height;
	rocketSprite.setOrigin(halfRocketWidth, halfRocketHeight);
	fireSprite.setOrigin(halfRocketWidth, -halfRocketHeight + 0.02 * halfRocketHeight);
	//Set the initial position of the rocket
//	pos = sf::Vector2f(400, 400);
	pos = sf::Vector2f(930, 292);
	rocketSprite.setPosition(pos);
	fireSprite.setPosition(pos);
	exhausting = true;
	circle = std::vector<Circles>(0);
	Triangle = std::vector<Triangles>(0);
//	Triangles tringle1 = Triangles(sf::Vector2f(389, 277), sf::Vector2f(360, 372), sf::Vector2f(429, 371), sf::Vector2f(0, 1), sf::Vector2f(1, 0), sf::Vector2f(-1, 0));
	Triangles tringle1 = Triangles(140);
	Triangle.push_back(tringle1);
	Triangle[0].setorigin(sf::Vector2f( halfRocketWidth, halfRocketHeight));
	Triangle[0].setpoisiton(sf::Vector2f(pos.x,pos.y));
	Triangle[0].scale(sf::Vector2f(scale, scale));
	Triangle[0].Triangleuppdate();
	Circles circle1 = Circles(10, 0, 0);
	circle.push_back(circle1);
}

Rocket::~Rocket()
{

}

void Rocket::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

	if (exhausting)
	{
		target.draw(fireSprite);
	}
	target.draw(rocketSprite);


		target.draw(circle[0]);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		target.draw(Triangle[0]);
	}
}

void Rocket::setPos(float x, float y)
{
	rocketSprite.setPosition(x, y);
	fireSprite.setPosition(x, y);
	Triangle[0].setpoisiton(sf::Vector2f(x,y));	
}

void Rocket::rotate(float degree)
{
	rocketSprite.rotate(degree);
	fireSprite.rotate(degree);
	Triangle[0].rotatetriangle(degree);
	

}

bool Rocket::colision(sf::Vector3f circle)
{

	if (true == collisioncheckbetweencirclesandtriangle(circle.x, circle.y, circle.z, Triangle[0].getpoint1(), Triangle[0].getpoint2(), Triangle[0].getpoint3(), Triangle[0].getside1normal(), Triangle[0].getside2normal(), Triangle[0].getside3normal()))
		return true;


	return false;
}

void Rocket::update(sf::Mouse & mouse, sf::Window & window)
{
	if (true == collisioncheckbetweencirclesandtriangle(circle[0].getplacex() + circle[0].getradius(), circle[0].getplacey() + circle[0].getradius(), circle[0].getradius(), Triangle[0].getpoint1(), Triangle[0].getpoint2(), Triangle[0].getpoint3(), Triangle[0].getside1normal(), Triangle[0].getside2normal(), Triangle[0].getside3normal()))
				std::cout << "woorks" << std::endl;
	circle[0].setplacex(mouse.getPosition(window).x);
	circle[0].setplacey(mouse.getPosition(window).y);
//	Triangle[0].setpoisiton((sf::Vector2f(mouse.getPosition(window).x,mouse.getPosition(window).y)));
	Triangle[0].Triangleuppdate();


}
