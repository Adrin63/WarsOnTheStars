#include "Stars.h"
#include <iostream>
#include "FAriasSimpleGraphics.h"

//Datos externos
			//extern char starSkins[3];
extern Game game;

//Constantes
const int MAX_INIT_STARS = 500;

//Variables
Star stars[MAX_INIT_STARS];

//Código
void Init_Stars()
{
	for (int i = 0; i < MAX_INIT_STARS; i++)
	{
		stars[i].starPos.X = rand() % game.W;
		stars[i].starPos.Y = rand() % game.H;
					//stars[i].starSkin = starSkins[rand() % 3];
	}
}

void Draw_Stars()
{
	for (int i = 0; i < MAX_INIT_STARS; i++)
	{
		FASG::WriteCharBuffer(stars[i].starPos.X, stars[i].starPos.Y, '*', FASG::EForeColor::LightWhite);	//stars[i].starSkin
	}
}