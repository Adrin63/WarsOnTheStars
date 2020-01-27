#pragma once
#include "FAriasSimpleGraphics.h"
enum SecPlayerMovement
{
	secRIGHT, secSTILL
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

void ShootSecondPlayer();

void ShootSecOff();

void ReciveSecPlayerDmg();