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
	PlayerMovement direction = PlayerMovement::STILL;

	Vector2D pos;
	float speed= 60.f;
				//char KeyPressed;	poner en engine, en menu hace unas cosas fuera de menu otra, switch case
	FASG::Sprite sprite = FASG::Sprite("Player.txt");
};

void DrawPlayer();
void InitPlayer();
void MovementPlayer();