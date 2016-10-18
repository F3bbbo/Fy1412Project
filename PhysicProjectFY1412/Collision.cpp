#include "Collision.h"
#include <iostream>

#define EPSILON 0.00001
bool collisioncheckbetweencircles(float x1, float y1, float radius1, float x2, float y2, float radius2)
{

	float Hypotenusan = ((x2 - x1)*(x2 - x1) + (y1 - y2)*(y1 - y2));
	float linebetweencircles = ((radius1 + radius2)*(radius1 + radius2));
	if (Hypotenusan <= linebetweencircles)
		return true;




	return false;
}
float lengthfunction(sf::Vector2f vector)
{

	return sqrt(vector.x*vector.x + vector.y*vector.y);


}
bool collisioncheckbetweencirclesandtriangle(float x1, float y1, float radius1, sf::Vector2f trianglepoint1, sf::Vector2f trianglepoint2, sf::Vector2f trianglepoint3, sf::Vector2f side1normal, sf::Vector2f side2normal, sf::Vector2f side3normal)
{

	x1 = x1;
	y1 = y1;
	//test one points inside circle
	sf::Vector2f circle; // circle center
	circle.x = x1;
	circle.y = y1;
	sf::Vector2f c1, c2, c3; // a vertex from the circles mid to each triangles position is created. 

	c1 = trianglepoint1 - circle;
	c2 = trianglepoint2 - circle;
	c3 = trianglepoint3 - circle;

	if (sqrt(c1.x*c1.x + c1.y*c1.y) <= (radius1))
	{
		return true;
	}
	if (sqrt(c2.x*c2.x + c2.y*c2.y) <= (radius1))
	{
		return true;
	}
	if (sqrt(c3.x*c3.x + c3.y*c3.y) <= (radius1))
	{
		return true;
	}
	/*
	*point 1
	/ \
	side1   /   \ side2
	/     \
	point2/_______\point3
	side3

	*/





	//test två edges collision;
	sf::Vector2f OL;
	c1 = trianglepoint1 - trianglepoint2; //side 1
	sf::Vector2f OT; //line between circle center and start of ray.  
	sf::Vector2f OV; //line from circle to OL                        _--* trianglepoint1
	OT = trianglepoint1 - circle;                         //    OT_--  /   /
	float normaliser = sqrt(c1.x*c1.x + c1.y *c1.y);//       	_-	  /   OL
	c1 = c1 / normaliser; // normalising the vector			  _-	 /   /
	float length; //                         		  circle o--OV->/   *
	length = OT.x*c1.x + OT.y*c1.y; // a projection from a to b    /
	OL.x = c1.x * length; // creates the vector	OL			      /
	OL.y = c1.y * length;									   //*trianglepoint2
															   //	length = lengthfunction(OL);							   /*	if ((circle.x+OL.x <= radius1) || (circle.y+OL.y <=radius1))
															   /*		   {
															   return true;
															   }
															   */

															   //	std::cout << length << std::endl;
															   //|| length>lengthfunction(trianglepoint2 - trianglepoint1) - radius1   (length>(lengthfunction(trianglepoint1 - trianglepoint2) + radius1)))
	if ((length<0) || (length>(lengthfunction(trianglepoint2 - trianglepoint1))))
	{

	}
	else
	{

		OV = OT - OL;
		if (sqrt(OV.x*OV.x + OV.y*OV.y) <= radius1)
		{
			return true;
		}

	}

	c2 = trianglepoint1 - trianglepoint3; //side 2
	OT = trianglepoint1 - circle;
	normaliser = sqrt(c2.x*c2.x + c2.y*c2.y);
	c2 = c2 / normaliser;
	length = OT.x*c2.x + OT.y*c2.y;
	OL.x = c2.x *length;
	OL.y = c2.y * length;

	if ((length<0.f) || (length>(lengthfunction(trianglepoint3 - trianglepoint1))))
	{

	}
	else
	{

		OV = OT - OL;
		if (sqrt(OV.x*OV.x + OV.y*OV.y) <= radius1)
		{
			return true;
		}

	}

	c3 = trianglepoint3 - trianglepoint2; //side 3
	OT = trianglepoint3 - circle;
	normaliser = sqrt(c3.x*c3.x + c3.y*c3.y);
	c3 = c3 / normaliser;
	length = OT.x*c3.x + OT.y*c3.y;
	OL.x = c3.x*length;
	OL.y = c3.y * length;

	if ((length<0.f) || (length>(lengthfunction(trianglepoint3 - trianglepoint2))))
	{

	}
	else
	{

		OV = OT - OL;
		if (sqrt(OV.x*OV.x + OV.y*OV.y) <= radius1)
		{
			return true;
		}

	}

	//test tre circle in triangle 
	//tar normalerna för cirkeln och projecerar den på normalen för trianglen
	//
	/*

	//side normal1
	c1 = trianglepoint1 - circle;  //creates stage1
	c2 = trianglepoint1 - trianglepoint2;     //creates stage 2
	float normalize = sqrt(c2.x*c2.x + c2.y *c2.y);
	c2 = c2 / normalize;
	length = c2.x * c1.x + c2.y * c1.y;
	c2.x = length*c2.x;
	c2.y = length * c2.y;
	c3 = -c2 + c1;
	float projectiontest;
	projectiontest = c3.x * side1normal.x + c3.y * side1normal.y;
	//check if test is negativ or positiv.
	if (projectiontest > 0)
	{
	//side normal1
	c1 = trianglepoint1 - circle;
	c2 = trianglepoint1 - trianglepoint3;
	normalize = sqrt(c2.x*c2.x + c2.y * c2.y);
	c2 = c2 / normalize;
	length = (c2.x * c1.x + c2.y * c1.y);
	c2.x = length * c2.x;
	c2.y = length *c2.y;
	c3 = -c2 + c1;
	projectiontest = c3.x *side2normal.x + c3.y * side2normal.y;
	if (projectiontest > 0)
	{
	c1 = trianglepoint2 - circle;
	c2 = trianglepoint2 - trianglepoint3;
	normalize = sqrt(c2.x*c2.x + c2.y * c2.y);
	c2 = c2 / normalize;
	length = (c2.x * c1.x + c2.y * c1.y);
	c2.x = length * c2.x;
	c2.y = length *c2.y;
	c3 = -c2 + c1;
	projectiontest = c3.x *side3normal.x + c3.y * side3normal.y;
	if (projectiontest > 0)
	return true;
	}
	}

	*/
	return false;
}
sf::Vector2f normaliser(sf::Vector2f position1)
{
	return	position1 / sqrt(position1.x*position1.x + position1.y*position1.y);
}
bool lineandcirclecollision(float x1, float y1, float radius1, sf::Vector2f point1, sf::Vector2f point2)
{
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
	std::cout << "endl break" << std::endl;
	}*/

	sf::Vector2f circle; // circle center
	circle.x = x1;
	circle.y = y1;
	//test två edges collision;
	sf::Vector2f OL;
	sf::Vector2f c1 = point1 - point2; //side 1
	sf::Vector2f OT; //line between circle center and start of ray.  
	sf::Vector2f OV; //line from circle to OL                        _--* trianglepoint1
	OT = point1 - circle;                                 //    OT_--  /   /
	float normaliser = sqrt(c1.x*c1.x + c1.y *c1.y);//       	_-	  /   OL
	c1 = c1 / normaliser; // normalising the vector			  _-	 /   /
	float length; //                         		  circle o--OV->/   *
	length = OT.x*c1.x + OT.y*c1.y; // a projection from a to b    /
	OL.x = c1.x * length; // creates the vector	OL			      /
	OL.y = c1.y * length;									   //*trianglepoint2
															   //	length = lengthfunction(OL);							   /*	if ((circle.x+OL.x <= radius1) || (circle.y+OL.y <=radius1))
															   /*														   {
															   return true;
															   }
															   */
															   //	std::cout << length << std::endl;
															   //|| length>lengthfunction(trianglepoint2 - trianglepoint1) - radius1   (length>(lengthfunction(trianglepoint1 - trianglepoint2) + radius1)))
	if ((length<0.f))
	{
		//	sf::Vector2f vector1test = (circle - point1);
		//		=vector1test.x*vector1test.x + vector1test.y*vector1test.y;

	}
	else if (length>(lengthfunction(point2 - point1)))
	{

	}
	else
	{

		OV = OT - OL;
		if (sqrt(OV.x*OV.x + OV.y*OV.y) <= radius1)
		{
			return true;
		}

	}
	return false;

	/*
	sf::Vector2f circle;
	circle.x = x1;
	circle.y = y1;
	sf::Vector2f OL=circle - point1;
	sf::Vector2f OT = point1 - point2;
	*/

}



bool collisioncheckbetweencircleandsquare(float x1, float y1, float radius1, sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f point3, sf::Vector2f point4)
{
	//test one points inside circle
	sf::Vector2f circle; // circle center
	circle.x = x1;
	circle.y = y1;
	sf::Vector2f c1, c2, c3, c4; // a vertex from the circles mid to each triangles position is created. 

	c1 = point1 - circle;
	c2 = point2 - circle;
	c3 = point3 - circle;
	c4 = point4 - circle;

	if (sqrt(c1.x*c1.x + c1.y*c1.y) <= (radius1))
	{
		return true;
	}
	if (sqrt(c2.x*c2.x + c2.y*c2.y) <= (radius1))
	{
		return true;
	}
	if (sqrt(c3.x*c3.x + c3.y*c3.y) <= (radius1))
	{
		return true;
	}
	if (sqrt(c4.x*c4.x + c4.y*c4.y) <= (radius1))
		return true;

	if (true == lineandcirclecollision(x1, y1, radius1, point2, point1))
		return true;
	if (true == lineandcirclecollision(x1, y1, radius1, point3, point2))
		return true;
	if (true == lineandcirclecollision(x1, y1, radius1, point4, point3))
		return true;
	if (true == lineandcirclecollision(x1, y1, radius1, point1, point4))
		return true;


	return false;
}

bool collisionLineLine(sf::Vector2f line1P1, sf::Vector2f line1P2, sf::Vector2f line2P1, sf::Vector2f line2P2)
{
	sf::Vector2f origin1 = line1P1;
	sf::Vector2f dist1 = line1P2 - line1P1;
	sf::Vector2f origin2 = line2P1;
	sf::Vector2f dist2 = line2P2 - line2P1;
	sf::Vector2f invDist1 = sf::Vector2f(-dist1.y, dist1.x);
	sf::Vector2f invDist2 = sf::Vector2f(-dist2.y, dist2.x);
	float test = dotProduct(dist1, invDist2);// if invdist2 ad dist1 gives 90 degress then its parlel since the inverse for dist1 that means that dist1 and dist2 is parallell
	if (-EPSILON < test && test < EPSILON)// parallell test 
	{
		return false;
	}
	else
	{
		float s = dotProduct((origin2 - origin1), invDist2) / test;
		float t = dotProduct((origin1 - origin2), invDist1) / dotProduct(dist2, invDist1);
		if (0 < s && s < 1 && 0 < t && t < 1)
		{
			return true;
		}

	}

	return false;
}

bool collisionsquareandtriangleintersection(Triangles triangle, Square square)
{	
	sf::Vector2f trianglepoint1, trianglepoint2, trianglepoint3,Squarepoint1,Squarepoint2,Squarepoint3,Squarepoint4;
	trianglepoint1=triangle.getpoint1();
	trianglepoint2=triangle.getpoint2();
	trianglepoint3=triangle.getpoint3();
	Squarepoint1 = square.getpoint1();
	Squarepoint2 = square.getpoint2();
	Squarepoint3 = square.getpoint3();
	Squarepoint4 = square.getpoint4();
	if (true == collisionLineLine(trianglepoint1, trianglepoint2, Squarepoint1, Squarepoint2))
		return true;
	if (true == collisionLineLine(trianglepoint1, trianglepoint2, Squarepoint2, Squarepoint3))
		return true;
	if (true == collisionLineLine(trianglepoint1, trianglepoint2, Squarepoint3, Squarepoint4))
		return true;
	if (true == collisionLineLine(trianglepoint1, trianglepoint2, Squarepoint4, Squarepoint1))
		return true;


	if (true == collisionLineLine(trianglepoint2, trianglepoint3, Squarepoint1, Squarepoint2))
		return true;
	if (true == collisionLineLine(trianglepoint2, trianglepoint3, Squarepoint2, Squarepoint3))
		return true;
	if (true == collisionLineLine(trianglepoint2, trianglepoint3, Squarepoint3, Squarepoint4))
		return true;
	if (true == collisionLineLine(trianglepoint2, trianglepoint3, Squarepoint4, Squarepoint1))
		return true;

	if (true == collisionLineLine(trianglepoint3, trianglepoint1, Squarepoint1, Squarepoint2))
		return true;
	if (true == collisionLineLine(trianglepoint3, trianglepoint1, Squarepoint2, Squarepoint3))
		return true;
	if (true == collisionLineLine(trianglepoint3, trianglepoint1, Squarepoint3, Squarepoint4))
		return true;
	if (true == collisionLineLine(trianglepoint3, trianglepoint1, Squarepoint4, Squarepoint1))
		return true;

	return false;
}


