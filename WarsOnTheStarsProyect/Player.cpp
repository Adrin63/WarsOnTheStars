#include "Player.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"
#include "Shoot.h"
#include <conio.h>

Player player;

PlayerMovement direction = PlayerMovement::STILL;
Game game;

Shoot pShoot;

extern float speed;

void InitPlayer()
{
	//vidas...
	player.sprite.LoadSprite("Player.txt");
	player.spriteInMove.LoadSprite("Player_Right.txt");
	player.sprite.Location.x = 10.f;
	player.sprite.Location.y = game.H * 0.5f;

	pShoot.shootPlayer.LoadSprite("Shoot.txt");
	pShoot.speedSh = 300.f;
	pShoot.ShootOn = false;
}

void ShootPlayer()
{
	FASG::WriteSpriteBuffer(pShoot.shootPlayer.Location.x, pShoot.shootPlayer.Location.y, pShoot.shootPlayer);
	pShoot.shootPlayer.Location.x += pShoot.speedSh * FASG::GetDeltaTime();

	if (pShoot.shootPlayer.Location.x >= 300)
	{
		pShoot.ShootOn = false;
	}
	
}

void DrawPlayer()
{
	switch (direction)
	{
		case PlayerMovement::RIGHT:
		FASG::WriteSpriteBuffer(player.sprite.Location.x, player.sprite.Location.y, player.spriteInMove);
		break;
		default: 
		FASG::WriteSpriteBuffer(player.sprite.Location.x, player.sprite.Location.y, player.sprite);
	}
}


void MovementPlayer()
{
	direction = PlayerMovement::STILL;

	if (FASG::IsKeyPressed('W'))
	{
		direction = PlayerMovement::UP;
		player.sprite.Location.y -= player.speed * FASG::GetDeltaTime();

		if (player.sprite.Location.y < 0)
			player.sprite.Location.y = 0;
	}

	if (FASG::IsKeyPressed('D'))
	{
		direction = PlayerMovement::RIGHT;
		player.sprite.Location.x += player.speed * FASG::GetDeltaTime();

		if (player.sprite.Location.x >= 170)
			player.sprite.Location.x = 170;
	}

	if (FASG::IsKeyPressed('S'))
	{
		direction = PlayerMovement::DOWN;
		player.sprite.Location.y += player.speed * FASG::GetDeltaTime();

		if (player.sprite.Location.y >= 54)
			player.sprite.Location.y = 54;
	}

	if (FASG::IsKeyPressed('A'))
	{
		direction = PlayerMovement::LEFT;
		player.sprite.Location.x -= player.speed * FASG::GetDeltaTime();

		if (player.sprite.Location.x < 0)
			player.sprite.Location.x = 0;
	}

	if (!pShoot.ShootOn)
	{
		pShoot.shootPlayer.Location.x = player.sprite.Location.x + 5;
		pShoot.shootPlayer.Location.y = player.sprite.Location.y + 2;
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
		FASG::WriteStringBuffer(30, FASG::EAligned::CENTER, "PRESIONE CUALQUIER TECLA PARA CONTINUAR", FASG::EForeColor::LightWhite);
		FASG::WriteStringBuffer(35, FASG::EAligned::CENTER, "O PARA VOLVER A LA PANTALLA PRINCIPAL", FASG::EForeColor::LightWhite);
		BackgroundWords(128, 172, 30);
		BackgroundWords(130, 170, 35);
		int a = toupper(_getch());

		if (a == 'O')
		{
			game.executable = false;
			game.gameplay = false;
		}
	}
}
	