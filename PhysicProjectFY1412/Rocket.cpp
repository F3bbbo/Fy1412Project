#include "Rocket.h"

#define PI 3.14159265


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
	oldposition = pos;
	colisionfire = false;
	unalterddt = 0;
	rocketSprite.setPosition(pos);
	fireSprite.setPosition(pos);
	// sets the bounding boxes for the rocket
	circle = std::vector<Circles>(0);
	Triangle = std::vector<Triangles>(0);
//	Triangles tringle1 = Triangles(sf::Vector2f(389, 277), sf::Vector2f(360, 372), sf::Vector2f(429, 371), sf::Vector2f(0, 1), sf::Vector2f(1, 0), sf::Vector2f(-1, 0));
	Triangles tringle1 = Triangles(140);
	Triangle.push_back(tringle1);
	Triangle[0].setorigin(sf::Vector2f( halfRocketWidth, halfRocketHeight));
	Triangle[0].setpoisiton(sf::Vector2f(pos.x,pos.y));
	Triangle[0].scale(sf::Vector2f(scale, scale));
	Triangle[0].Triangleuppdate();
	origin = sf::Vector2f(halfRocketWidth, halfRocketHeight);
	Circles circle1 = Circles(10, 0, 0);
	circle.push_back(circle1);
	Squares = std::vector<Square>(0);
	Square square1 = Square(280, 140);
	Squares.push_back(square1);
	Squares[0].setorigin(sf::Vector2f(halfRocketWidth - 20, -(halfRocketHeight) / 2.6));
	Squares[0].setpoisiton(pos);
	Squares[0].scale(sf::Vector2f(scale, scale));
	square1 = Square(180, 130);
	Squares.push_back(square1);
	Squares[1].setorigin(sf::Vector2f(halfRocketWidth - 60, 0.f + 37));
	Squares[1].setpoisiton(pos);
	Squares[1].scale(sf::Vector2f(scale, scale));
	//ScreenText
	screenText.textFont.loadFromFile("Textures\\fonts\\STENCIL.TTF");
	screenText.fuelMass.setFont(screenText.textFont);
	screenText.fuelMass.setPosition(1000, 100);
	screenText.fuelMass.setCharacterSize(30);
	screenText.fuelMass.setStyle(sf::Text::Bold);
	screenText.fuelMass.setColor(sf::Color::White);
	screenText.velocity.setFont(screenText.textFont);
	screenText.velocity.setPosition(1000, 150);
	screenText.velocity.setCharacterSize(30);
	screenText.velocity.setStyle(sf::Text::Bold);
	screenText.velocity.setColor(sf::Color::White);
;


	//Set physics variables
	reset();
}

Rocket::~Rocket()
{

}

void Rocket::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	//flame
	if (physics.thrust && physics.fuelMass > 0.0f)
	{
		target.draw(fireSprite);
	}
	//rocket
	if(colisionfire==false)
	{
	target.draw(rocketSprite);
	}

	//hitbox
		target.draw(circle[0]);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		target.draw(Triangle[0]);
		target.draw(Squares[0]);
		target.draw(Squares[1]);
	}
	//explosion
	target.draw(explosions);
	//screentext
	target.draw(screenText.fuelMass);
	target.draw(screenText.velocity);
}

void Rocket::setPos(float x, float y)
{
	rocketSprite.setPosition(x, y);
	fireSprite.setPosition(x, y);
	Triangle[0].setpoisiton(sf::Vector2f(x,y));	
	for (int i = 0;i < 2;i++)
	{
		Squares[i].setpoisiton(sf::Vector2f(x, y));
	}
	
	
	
	
	
}

void Rocket::setRotation(float degree)
{
	rocketSprite.setRotation(degree);
	fireSprite.setRotation(degree);
	Triangle[0].setrotate(degree);
	for (int i = 0;i < 2;i++)
	{
		Squares[i].setrotatesquare(degree);
	}


	//set physics variables
	//physics.angle = degree;
	//setDir(physics.angle);
}

void Rocket::setRotation()
{
	setRotation(physics.angle);
}

void Rocket::setThrust(float thrust)
{
	physics.thrust = thrust;
}

void Rocket::setDir(float degree)
{
	degree = degree * PI / 180;
	physics.thrustDir.x = sin(degree);
	physics.thrustDir.y = -cos(degree);
	physics.velDir.x = sin(degree);
	physics.velDir.y = -cos(degree);

}

float Rocket::thrustForce()
{
	return physics.thrust * physics.dMass * physics.VeSize;
}

sf::Vector2f Rocket::totalForce(Earth &earth)
{
	sf::Vector2f returnForce = physics.velDir * thrustForce() + gForce(earth);
	return returnForce;
}

sf::Vector2f Rocket::gForce(Earth &earth)
{
	sf::Vector2f gDir = earth.getWorldPos() - physics.position;
	float radius = length(gDir);
	gDir /= radius;
	//std::cout << earth.acceleration(radius) << std::endl;
	return gDir * earth.acceleration(radius) * (physics.fuelMass + physics.rocketMass);
}


sf::Vector2f Rocket::nextVelocity(float dt, Earth &earth)
{
	sf::Vector2f nextVel = physics.velDir * physics.velocity + totalForce(earth) / (physics.fuelMass + physics.rocketMass) * dt;
	physics.velocity = length(nextVel);
	physics.velDir = nextVel / physics.velocity;
	if(physics.velDir.x > 0)
		physics.angle = acos(-physics.velDir.y) * 180 / PI;
	else
		physics.angle = 360 - acos(-physics.velDir.y) * 180 / PI;

	return nextVel;
}

sf::Vector2f Rocket::nextPosition(float dt)
{
	physics.position += physics.velDir * physics.velocity * dt;
	return physics.position;
}

void Rocket::updateMass(float dt)
{
	physics.fuelMass -= physics.thrust * physics.dMass * dt;
	if (physics.fuelMass < 0)
	{
		physics.fuelMass = 0;
		physics.dMass = 0;
	}
}

void Rocket::rotate(float degree)
{
	if (-35 < physics.angle + degree && physics.angle + degree < 35 )
	{
		rocketSprite.rotate(degree);
		fireSprite.rotate(degree);
		Triangle[0].rotatetriangle(degree);
		physics.angle += degree;
		setDir(physics.angle);
	}
}

void Rocket::reset()
{
	pos = sf::Vector2f(930, 292);
	rocketSprite.setPosition(pos);
	fireSprite.setPosition(pos);
	pos = sf::Vector2f(930, 292);
	physics.angle = 0;
	physics.dMass = 100;
	physics.fuelMass = 13000;
	physics.rocketMass = 1000;
	physics.VeSize = 3000;
	physics.velocity = 300;
	physics.position = makeWorldPos(pos);
	physics.velDir = sf::Vector2f(0, -1);
	physics.thrust = 0.0f;
	setDir(physics.angle);
	setRotation();
	explosions.resetfunction();
	//screentext
	screenText.fuelMass.setString("Fuel Mass: " + toString(physics.fuelMass, 0));
	screenText.velocity.setString("Velocity: 0");
	colisionfire = false;
	unalterddt = 0;
}

bool Rocket::colision(sf::Vector3f circle)
{

	if (true == collisioncheckbetweencirclesandtriangle(circle.x, circle.y, circle.z, Triangle[0].getpoint1(), Triangle[0].getpoint2(), Triangle[0].getpoint3(), Triangle[0].getside1normal(), Triangle[0].getside2normal(), Triangle[0].getside3normal()))
		return true;
	for (int i = 0;i<2;i++)
	{
		if (true == collisioncheckbetweencircleandsquare(circle.x, circle.y, circle.z, Squares[i].getpoint1(), Squares[i].getpoint2(), Squares[i].getpoint3(), Squares[i].getpoint4()))
			return true;
	}
	return false;
}

void Rocket::update(sf::Mouse & mouse, sf::Window & window, Earth &earth, float dt, bool colision)
{
	unalterddt = unalterddt + dt;
	if (unalterddt <= 2)
	{
		colision = false;
	}
	colisionfire = colision;
	float rocketdt;
	rocketdt = dt * 100;

//	circle[0].setplacex(mouse.getPosition(window).x);
//	circle[0].setplacey(mouse.getPosition(window).y);
//	Triangle[0].setpoisiton((sf::Vector2f(mouse.getPosition(window).x,mouse.getPosition(window).y)));
	//Physics
	if(colision == false)
	{
	nextPosition(rocketdt);
	nextVelocity(rocketdt, earth);
	updateMass(rocketdt);
	//Screen
	screenText.velocity.setString("Velocity: " + toString(physics.velocity, 0));
	screenText.fuelMass.setString("Fuel Mass: " + toString(physics.fuelMass, 0));
	setRotation();
	pos = makeScreenPos(physics.position);
	setPos(pos.x, pos.y);
	oldposition = pos;
	}
	if(colision == true)
	explosions.update(origin, sf::Vector2f(oldposition.x, oldposition.y), rocketdt/10);// EXPLOSION

	if(colision == false)
	{
	Triangle[0].Triangleuppdate();
	Squares[0].SquareUpdate();
	Squares[1].SquareUpdate();
	}
	//std::cout << physics.velDir.x << " " << physics.velDir.y << std::endl;
	//std::cout << physics.angle << std::endl;
}
