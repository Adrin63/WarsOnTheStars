#pragma once
#include "Engine.h"
#include "FAriasSimpleGraphics.h"

enum enemiMovement
{
	enDOWN, enUP
};

struct TypeEnemieLittle
{
	Vector2D pos;
	float speed;
	FASG::Sprite sprite;
	int vida = 1;
};

struct TypeEnemieMedium
{
	Vector2D pos;
	float speed;
	FASG::Sprite sprite;
	int vida = 5;
};

struct TypeEnemieLarge
{
	Vector2D pos;
	float speed;
	FASG::Sprite sprite;
	int vida = 10;
};

/*
FASG::Sprite spriteEnMiddle = FASG::Sprite("EnemieLittle.txt");
FASG::Sprite spriteEnGiga = FASG::Sprite("EnemieLittle.txt");
FASG::Sprite spriteEnBigChungus = FASG::Sprite("EnemieLittle.txt");
*/

void InitEnemies();
void DrawEnemies();
