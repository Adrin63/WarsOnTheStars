#pragma once
#include "Engine.h"

//Struct para cada estrella y su posici�n
struct Star
{
	float X = 0;
	float Y = 0;
};

//Iniciar Estrellas
void InitStars();

//Dibujar Estrellas
void DrawStars(bool a);