#pragma once
#include "Engine.h"
#include "FAriasSimpleGraphics.h"

/*enum PlayerState
{
	NORMAL - INVENCIBLE - POWERUPS EN GENERAL, INCLUSO EN PROPULSION SE PUEDE PONER EL HAZ
};*/

enum PlayerMovement
{
	UP, DOWN, LEFT, RIGHT, STILL //quietoxd
};

struct Player
{
	PlayerMovement direction = PlayerMovement::STILL;

	Vector2D pos;
	//Vector2D speed;
	float speed= 40.f;
	FASG::Sprite sprite = FASG::Sprite("Player.txt");
};

void DrawPlayer();
void InitPlayer();
void MovementPlayer();