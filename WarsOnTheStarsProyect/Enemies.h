#pragma once
#include "Engine.h"
#include "FAriasSimpleGraphics.h"

enum enemiMovement
{
	enDOWN, enUP
};

struct TypeEnemieLittle
{
	FASG::Sprite sprite;
	int vida = 1;
};

struct TypeEnemieMedium
{
	FASG::Sprite sprite;
	int vida = 5;
};

struct TypeEnemieLarge
{
	FASG::Sprite sprite;
	int vida = 10;
};

void InitEnemies();
void DrawEnemies();

void MovementLittle();
void MovementMiddle();
void MovementLarge();

void FinalState();

int envLitEnQuantity();
int envMidEnQuantity();
int envLarEnQuantity();

void ReciveLitDmg(int a);
void ReciveMidDmg(int b);
void ReciveLarDmg(int c);