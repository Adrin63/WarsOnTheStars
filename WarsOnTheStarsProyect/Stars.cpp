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
			stars[i][l].X = rand() % game.W;
			stars[i][l].Y = rand() % game.H;
		}
	}
}

//Mostrar las estrellas en pantalla y en caso de que se vayan de esta reiniciarlas, en la preparación a la fase final se aceleran
void DrawStars(bool a)
{
	for (int i = 0; i < MAX_INIT_STARS; i++)
	{
		

		switch (a)
		{
		case true:
			stars[i][i].X -= 1.5;
			FASG::WriteCharBuffer(stars[i][i].X, stars[i][i].Y, '*', FASG::EForeColor::LightWhite);
			break;
		case false:
			FASG::WriteCharBuffer(stars[i][i].X, stars[i][i].Y, '-', FASG::EForeColor::LightWhite);
			stars[i][i].X -= 4.5;
			break;
		}

		if (stars[i][i].X <= 0)
		{
			stars[i][i].X = 300;
		}
	}
}