#pragma once
#include "Engine.h"
#include "FAriasSimpleGraphics.h"

//Posiciones de movimiento del jugador
enum PlayerMovement
{
	UP, DOWN, LEFT, RIGHT, STILL
};

//El propio jugador
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