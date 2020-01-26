#include "Stars.h"
#include <iostream>
#include "FAriasSimpleGraphics.h"

//Variables de game para determinar el punto donde estas del juego
extern Game game;

//Cantidad de Estrellas
const int MAX_INIT_STARS = 150;

//Matriz para las estrellas
Star stars[MAX_INIT_STARS][MAX_INIT_STARS];


//Inizializar las estrellas
void InitStars()
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

//Mostrar las estrellas en pantalla y en caso de que se vayan de esta reiniciarlas
void DrawStars()
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