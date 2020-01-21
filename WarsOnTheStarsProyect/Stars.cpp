#include "Stars.h"
#include <iostream>
#include "FAriasSimpleGraphics.h"

extern Game game;


const int MAX_INIT_STARS = 150;

Star stars[MAX_INIT_STARS][MAX_INIT_STARS];

void Init_Stars()
{
	for (int i = 0; i < MAX_INIT_STARS; i++)
	{
		for (int l = 0; l < MAX_INIT_STARS; l++)
		{
			stars[i][l].starPos.X = rand() % game.W;
			stars[i][l].starPos.Y = rand() % game.H;
		}
	}
}

void Draw_Stars()
{
	for (int i = 0; i < MAX_INIT_STARS; i++)
	{
		FASG::WriteCharBuffer(stars[i][i].starPos.X, stars[i][i].starPos.Y, '*', FASG::EForeColor::LightWhite);
		stars[i][i].starPos.X-=1.5;

		if (stars[i][i].starPos.X <= 0)
		{
			stars[i][i].starPos.X = 300;
		}
	}
}