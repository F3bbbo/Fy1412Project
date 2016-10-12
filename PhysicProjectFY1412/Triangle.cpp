#include "Triangle.h"

void Triangles::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(triangle);
}

void Triangles::Update(float dt)
{
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		
		int Number = getpoint1().x;
		std::string String = std::to_string(Number);
		//		string String = static_cast<ostringstream*>(&(ostringstream() << Number))->str();
		std::cout << "xvalue point1" << String << std::endl;
		Number = getpoint1().y;
		String = std::to_string(Number);
		std::cout << "yvalue point1" << String << std::endl;
	}*/
}

Triangles::Triangles()
{
}

Triangles::Triangles(float radien)
{
	


	triangle.setRadius(radien);
//	triangle.setPointCount(3); //triangle.getPosition();
	triangle.setPosition(sf::Vector2f(200, 200));
	this->trianglepoint1 = sf::Vector2f(0 ,0); //triangle.getPoint(0);
	this->trianglepoint2 = sf::Vector2f(0, 0);//triangle.getPoint(2);
	this->trianglepoint3 = sf::Vector2f(0, 0);// triangle.getPoint(1);
	this->side1normal = triangle.getPoint(0);
	this->side2normal = triangle.getPoint(0);
	this->side3normal = triangle.getPoint(0);
	triangle.setPointCount(3);
	
}

Triangles::~Triangles()
{

}

void Triangles::Triangleuppdate()
{
	float kordinatochbred[4];
	kordinatochbred[0]=triangle.getGlobalBounds().left; //left vänstrapunkten högst upp på fyrkantens x kordinat. och top är des y kordinat. width är bredden på hela och height är höjden.
	kordinatochbred[1] = triangle.getGlobalBounds().top;
	kordinatochbred[2] = triangle.getGlobalBounds().width;
	kordinatochbred[3] = triangle.getGlobalBounds().height;
	triangle.setRadius(140);
	this->trianglepoint1 = sf::Vector2f(kordinatochbred[0]+(kordinatochbred[2]/2), kordinatochbred[1]);//triangle.getPoint(0);
	this->trianglepoint2 = sf::Vector2f(kordinatochbred[0], kordinatochbred[1] + kordinatochbred[3]);
	this->trianglepoint3 = sf::Vector2f(kordinatochbred[0] + kordinatochbred[2],kordinatochbred[1]+kordinatochbred[3]);
}



sf::Vector2f Triangles::getpoint1()
{
	return this->trianglepoint1;
}

sf::Vector2f Triangles::getpoint2()
{
	return this->trianglepoint2;
}

sf::Vector2f Triangles::getpoint3()
{
	return this->trianglepoint3;
}

sf::Vector2f Triangles::getside1normal()
{
	return side1normal;
}

sf::Vector2f Triangles::getside2normal()
{
	return side2normal;
}

sf::Vector2f Triangles::getside3normal()
{
	return side3normal;
}

void Triangles::movetolocalspace(sf::Vector2f centrumrotation)
{
	settrianglepoint1(getpoint1() - centrumrotation);
	settrianglepoint2(getpoint2() - centrumrotation);
	settrianglepoint3(getpoint3() - centrumrotation);
}

void Triangles::scale(sf::Vector2f scale)
{
	triangle.setScale(scale);
}

void Triangles::movetoworldspace(sf::Vector2f centrumrotation)
{
	settrianglepoint1(getpoint1() + centrumrotation);
	settrianglepoint2(getpoint2() + centrumrotation);
	settrianglepoint3(getpoint3() + centrumrotation);

}

void Triangles::movepos(sf::Vector2f rocketpos)
{

}
void Triangles::setpoisiton(sf::Vector2f position)
{
	triangle.setPosition(position);
}
void Triangles::setorigin(sf::Vector2f origin)
{
	triangle.setOrigin(origin);
}

void Triangles::settrianglepoint1(sf::Vector2f trianglepoint1)
{
	this->trianglepoint1 = trianglepoint1;

}

void Triangles::settrianglepoint2(sf::Vector2f trianglepoint2)
{
	this->trianglepoint2 = trianglepoint2;
}

void Triangles::settrianglepoint3(sf::Vector2f trianglepoint3)
{
	this->trianglepoint3 = trianglepoint3;
}

void Triangles::setside1normal(sf::Vector2f side1normal)
{
	this->side1normal = side1normal;

}

void Triangles::setside2normal(sf::Vector2f side2normal)
{
	this->side2normal = side2normal;

}

void Triangles::setside3normal(sf::Vector2f side3normal)
{
	this->side3normal = side3normal;
}

void Triangles::rotatetriangle(float degree)
{
	triangle.rotate(degree);
	Triangleuppdate();
}

void Triangles::movetolocalspaceandrotatetriangle(sf::Vector2f rocketpos, float degree)
{

}
//string.reserve(512);