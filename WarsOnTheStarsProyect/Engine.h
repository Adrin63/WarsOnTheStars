#pragma once
#include <iostream>

//Struct que tiene todas las booleanas para ir de una parte a otra del juego, ademas del tamaño de la consola
struct Game
{
	int W, H;
	bool gameplay = false;
	bool executable = false;
	bool login = true;
	bool difficulty = false;
	bool howToPlay = false;
	bool end = false;
	bool win = false;
};

//Poner fondo de color, usado en las palabras
void BackgroundWords(int initialX, int finalX, int Y);

//Función que engloba todo lo que inicia el juego
void InitGame();

//Función que engloba todo lo que dibuja el juego
void DrawGame();

//Función de las colisiones
void Colisions(std::string tag1, std::string tag2);

//Restar el tiempo a variables de CD
void TimeMinus(float &b);