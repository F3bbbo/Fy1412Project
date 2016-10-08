#include "Collision.h"

bool collisioncheckbetweencircles(float x1, float y1, float radius1, float x2, float y2, float radius2)
{

	float Hypotenusan = ((x2 - x1)*(x2 - x1) + (y1 - y2)*(y1 - y2));
	float linebetweencircles = ((radius1 + radius2)*(radius1 + radius2));
	if (Hypotenusan <= linebetweencircles)
		return true;




	return false;
}

bool collisioncheckbetweencirclesandtriangle(float x1, float y1, float radius1, sf::Vector2f trianglepoint1, sf::Vector2f trianglepoint2, sf::Vector2f trianglepoint3, sf::Vector2f side1normal, sf::Vector2f side2normal, sf::Vector2f side3normal)
{
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
	c1 = trianglepoint2 - trianglepoint1; //side 1
	sf::Vector2f OT; //line between circle center and start of ray.  
	sf::Vector2f OV; //line from circle to OL                        _--* trianglepoint1
	OT = trianglepoint1 - circle;                         //    OT_--  /   /
	float normaliser = sqrt(c1.x*c1.x + c1.y *c1.y);//       	_-	  /   OL
	c1 = c1 / normaliser; // normalising the vector			  _-	 /   /
	float length; //                         		  circle o--OV->/   *
	length = OT.x*c1.x + OT.y*c1.y; // a projection from a to b    /
	OL.x = c1.x * length; // creates the vector	OL			      /
	OL.y = c1.y * length;									   //*trianglepoint2
															   /*	if ((circle.x+OL.x <= radius1) || (circle.y+OL.y <=radius1))
															   {
															   return true;
															   }
															   */


	if (length<0.f || length>



	OV = OT - OL;
	if (sqrt(OV.x*OV.x + OV.y*OV.y) <= radius1)
	{
		return true;
	}


	c2 = trianglepoint3 - trianglepoint1; //side 2
	OT = trianglepoint1 - circle;
	normaliser = sqrt(c2.x*c2.x + c2.y*c2.y);
	c2 = c2 / normaliser;
	length = OT.x*c2.x + OT.y*c2.y;
	OL.x = c2.x *length;
	OL.y = c2.y * length;
	OV = OT - OL;
	if (sqrt(OV.x*OV.x + OV.y*OV.y) <= radius1)
	{
		return true;
	}

	c3 = trianglepoint3 - trianglepoint2; //side 3
	OT = trianglepoint3 - circle;
	normaliser = sqrt(c3.x*c3.x + c3.y*c3.y);
	c3 = c3 / normaliser;
	length = OT.x*c3.x + OT.y*c3.y;
	OL.x = c3.x*length;
	OL.y = c3.y * length;
	OV = OT - OL;
	if (sqrt(OV.x*OV.x + OV.y*OV.y) <= radius1)
	{
		return true;
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



