#include "House.h"

Houses::Houses()
{
	Texture[1].loadFromFile("Textures\\game\\huset\housebrokenglass.png");
	Texture[3].loadFromFile("Textures\\game\\Explosions\\housebrokenglassandcrashed.png");
	Texture[2].loadFromFile("Textures\\game\\Explosions\\housebrokenglassandhalfcrashed.png");
	Texture[0].loadFromFile("Textures\\game\\Explosions\\housewithglas.png");
}

void Houses::changesprite(float P)
{
	if (700000 <= P <= 800000);
}

Houses::~Houses()
{
}
