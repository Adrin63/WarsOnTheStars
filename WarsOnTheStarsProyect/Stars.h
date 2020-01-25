#pragma once
#include "Engine.h"

struct Star
{
	Vector2D starPos;
	float starSpeed = 0;
	char starSkin;
	char starSkins[3] = { '*','.','+' };
};

void Init_Stars();
void DrawStars();