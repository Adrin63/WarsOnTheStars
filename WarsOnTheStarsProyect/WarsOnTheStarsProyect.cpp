// WarsOnTheStarsProyect.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <time.h>
#include "Engine.h";
#include "Background.h";
#include "FAriasSimpleGraphics.h";

//Height = 50
//Width = 200

int main()
{
	srand(time(NULL));

	Background();

	//FASG::InitConsole(W, H);
}
