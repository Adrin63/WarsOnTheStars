#pragma once
#include "Engine.h"
#include "FAriasSimpleGraphics.h"

enum PlayerMovement
{
	UP, DOWN, LEFT, RIGHT, STILL
};

struct Player
{
	float speed= 90.f;
	int life;
	FASG::Sprite spriteInMove;
	FASG::Sprite sprite;
};

void DrawPlayer();
void InitPlayer();
void MovementPlayer();
void ShootPlayer();

void ShootOff(bool a);

void RecivePlayerDmg(bool dmg);