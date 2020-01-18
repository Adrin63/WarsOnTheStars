#include "Player.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"
#include "Shoot.h"
#include "LoginScreen.h"
#include <conio.h>

Player player;

Game game;

Shoot pShoot;

extern float speed;

void InitPlayer()
{
	//vidas...
	player.pos.X = 10.f;
	player.pos.Y = game.H *0.5f;

	pShoot.speedSh = 300.f;
	pShoot.ShootOn = false;
}

void ShootPlayer()
{
	FASG::WriteSpriteBuffer(pShoot.posSh.X, pShoot.posSh.Y, pShoot.shootPlayer);
	pShoot.posSh.X += pShoot.speedSh * FASG::GetDeltaTime();

	if (pShoot.posSh.X >= 300)
	{
		pShoot.ShootOn = false;
		pShoot.posSh.X = player.pos.X + 5;
		pShoot.posSh.Y = player.pos.Y + 2;
	}
	
}

void DrawPlayer()
{
	FASG::WriteSpriteBuffer(player.pos.X, player.pos.Y, player.sprite);
}


void MovementPlayer()
{
	if (FASG::IsKeyPressed('W'))
	{
		PlayerMovement direction = PlayerMovement::UP;
		player.pos.Y -= player.speed * FASG::GetDeltaTime();

		if (player.pos.Y < 0)
			player.pos.Y = 0;
	}

	if (FASG::IsKeyPressed('D'))
	{
		PlayerMovement direction = PlayerMovement::RIGHT;
		player.pos.X += player.speed * FASG::GetDeltaTime();

		if (player.pos.X >= 286)
			player.pos.X = 286;
	}

	if (FASG::IsKeyPressed('S'))
	{
		PlayerMovement direction = PlayerMovement::DOWN;
		player.pos.Y += player.speed * FASG::GetDeltaTime();

		if (player.pos.Y >= 54)
			player.pos.Y = 54;
	}

	if (FASG::IsKeyPressed('A'))
	{
		PlayerMovement direction = PlayerMovement::LEFT;
		player.pos.X -= player.speed * FASG::GetDeltaTime();

		if (player.pos.X < 0)
			player.pos.X = 0;
	}

	if (!pShoot.ShootOn)
	{
		pShoot.posSh.X = player.pos.X + 5;
		pShoot.posSh.Y = player.pos.Y + 2;
	}

	if (FASG::IsKeyPressed('J'))
	{
		pShoot.ShootOn = true;
	}

	if (pShoot.ShootOn)
	{
		ShootPlayer();
	}

	if (FASG::IsKeyPressed('P'))
	{
		FASG::WriteStringBuffer(30, FASG::EAligned::CENTER, "PRESIONE CUALQUIER TECLA PARA CONTINUAR", FASG::EForeColor::Black);
		FASG::WriteStringBuffer(35, FASG::EAligned::CENTER, "O PARA VOLVER AL MENU", FASG::EForeColor::Black);
		BackgroundWords(128, 172, 30);
		BackgroundWords(137, 163, 35);
		int a = toupper(_getch());
		if (a == 'O')
		{
			game.executable = true;
			game.gameplay = true;
		}
	}
}
	