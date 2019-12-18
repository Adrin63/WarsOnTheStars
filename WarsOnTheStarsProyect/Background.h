#pragma once
#include "Engine.h"

struct Star
{
	Vector2D starPos;
	float starSpeed = 0;
	char starSkin[3] = { '*','.','+' };
	//FALTA COLOR ESTRELLAS (VARIAR ENTRE BLANCO Y AMARILLO PALIDO)
		//void WriteCharBuffer(int x, int y, char _char, EForeColor color);
};

void Init_Stars();
void Draw_Stars();