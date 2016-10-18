#ifndef ROCKET_H
#define ROCKET_H
#include <SFML/Graphics.hpp>
#include <math.h>
#include "Triangle.h"
#include "Collision.h"
#include "circle.h"
#include "Earth.h"
#include "Square.h"
#include "Explosions.h"
class Rocket : public sf::Drawable
{
	struct Physics
	{
		float VeSize;
		float velocity;
		sf::Vector2f velDir;
		sf::Vector2f thrustDir;
		sf::Vector2f position;
		float dMass;
		float fuelMass;
		float rocketMass;
		float angle;
		float thrust;
	};
	struct ScreenText
	{
		sf::Font textFont;
		sf::Text velocity;
		sf::Text fuelMass;
	};
private:
	sf::Sprite rocketSprite;
	sf::Texture rocketTex;
	sf::Sprite fireSprite;
	sf::Texture fireTex;
	sf::Vector2f pos;
	sf::Vector2f origin;
	sf::Clock clock;
	float P;
	std::vector<Circles> circle;
	std::vector<Triangles>Triangle;
	std::vector<Square>Squares;
	void setRotation(float degree);
	void setRotation();
	Physics physics;
	//Physics functions
	void setDir(float degree);
	float thrustForce();
	sf::Vector2f totalForce(Earth &earth);
	sf::Vector2f gForce(Earth &earth);
	//void rotateDir(float degree);
	bool onlyonece;
	sf::Vector2f nextVelocity(float dt, Earth &earth);
	sf::Vector2f nextPosition(float dt);
	void updateMass(float dt);
	explosion explosions;
	sf::Vector2f oldposition;
	bool colisionfire;

	float unalterddt;
	float otherdt;
	ScreenText screenText;
public:
	float preturner();
	void setThrust(float thrust);
	float returnp();
	Rocket();
	~Rocket();
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void setPos(float x, float y);
	void rotate(float degree);
	bool explosionDone();
	void reset();
	bool colision(sf::Vector3f circle, Square &square);
	bool colisionhouse(Square &square );
	bool colisionexplosionandhouse(Square square);
	void update(sf::Mouse &mouse, sf::Window &window, Earth &earth, float dt, bool colision, bool explosioncolideswithhouse);
};


#endif