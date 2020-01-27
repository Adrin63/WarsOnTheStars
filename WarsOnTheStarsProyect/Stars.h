#pragma once
#include "Engine.h"

//Struct para cada estrella
struct Star
{
	float X = 0;
	float Y = 0;

	float starSpeed = 0;
	char starSkin;
	char starSkins[3] = { '*','.','+' };
};

//Iniciar Estrellas
void InitStars();

//Dibujar Estrellas
void DrawStars(bool a);