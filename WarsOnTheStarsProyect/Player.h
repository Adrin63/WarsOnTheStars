#pragma once
#include "Engine.h"
#include "FAriasSimpleGraphics.h"

/*enum PlayerState
{
	NORMAL - INVENCIBLE - POWERUPS EN GENERAL, INCLUSO EN PROPULSION SE PUEDE PONER EL HAZ
};*/

enum PlayerMovement
{
	UP, DOWN, LEFT, RIGHT, STILL
};

struct Player
{
	Vector2D pos;
	float speed= 90.f;
	FASG::Sprite sprite2 = FASG::Sprite("Player_Right.txt");
	FASG::Sprite sprite = FASG::Sprite("Player.txt");
};

void DrawPlayer();
void InitPlayer();
void MovementPlayer();
void ShootPlayer();