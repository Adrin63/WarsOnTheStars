#pragma once
#include "Engine.h"
#include "FAriasSimpleGraphics.h"

struct Enemie
{
	Vector2D pos;
	float speed;
	FASG::Sprite spriteEn = FASG::Sprite("Enemie.txt");
};

void InitEnemies();
void DrawEnemies();