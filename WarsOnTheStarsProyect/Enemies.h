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

void InitEnemies();
void DrawEnemies();

void MovementLittle();
void MovementMiddle();
void MovementLarge();