#include "SecondPlayer.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"
//arreglar este extern, solo necesitas el game.H
extern Game game;

SecPlayer secPlayer;

SecPlayerMovement secDirection;

ShootSecP secpShoot;

void InitSecPlayer()
{
	secPlayer.sprite.LoadSprite("secPlayer.txt");
	FASG::Sprite::AddToCollisionSystem(secPlayer.sprite, "secPlayer");

	secPlayer.spriteInMove.LoadSprite("secPlayer_Right.txt");
	FASG::Sprite::AddToCollisionSystem(secPlayer.spriteInMove, "secPlayerInMove");

	//vendria el switch en caso de que este o no en pantalla
	secPlayer.spriteInMove.Location.x = -80;
	secPlayer.spriteInMove.Location.y = -80;

	secPlayer.sprite.Location.x = 10.f;
	secPlayer.sprite.Location.y = game.H * 0.25f;
}

void DrawSecPlayer()
{

}

void MovementSecPlayer()
{

}
