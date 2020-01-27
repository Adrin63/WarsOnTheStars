#pragma once
#include "FAriasSimpleGraphics.h"
enum SecPlayerMovement
{
	secUP, secDOWN, secLEFT, secRIGHT, secSTILL
};

struct SecPlayer
{
	float speed;
	int life;
	FASG::Sprite spriteInMove;
	FASG::Sprite sprite;
};

struct ShootSecP
{
	float speedSh;
	bool ShootOn;
	FASG::Sprite shootPlayer;
};

void InitSecPlayer();

void DrawSecPlayer();

void MovementSecPlayer();