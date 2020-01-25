#include "Player.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"
#include "Shoot.h"
#include <conio.h>
#include "Difficulty.h"

Player player;

PlayerMovement direction = PlayerMovement::STILL;
Game game;

Shoot pShoot;

extern float speed;

Diff difficult;
void InitPlayer()
{
	player.sprite.LoadSprite("Player.txt");
	player.spriteInMove.LoadSprite("Player_Right.txt");
	FASG::Sprite::AddToCollisionSystem(player.sprite, "Player");
	FASG::Sprite::AddToCollisionSystem(player.spriteInMove, "PlayerInMove");

	player.sprite.Location.x = 10.f;
	player.sprite.Location.y = game.H * 0.5f;

	pShoot.shootPlayer.LoadSprite("Shoot.txt");
	FASG::Sprite::AddToCollisionSystem(pShoot.shootPlayer, "ShootPlayer");
	pShoot.speedSh = 300.f;
	pShoot.ShootOn = false;

	difficult = envDifficulty();

	switch (difficult)
	{
	case INMORTAL:
		player.life = 99;
		break;
	case NORMAL:
		player.life = 3;
		break;
	case ONE:
		player.life = 1;
		break;
	}
}

void DrawPlayer()
{
	if (player.life >= 0)
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
	else
	{
		game.gameplay = false;
		game.end = true;
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
		FASG::WriteStringBuffer(35, FASG::EAligned::CENTER, "O PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);
		BackgroundWords(129, 171, 30);
		BackgroundWords(138, 162, 35);
		int a = toupper(_getch());

		if (a == 'O')
		{
			game.gameplay = false;
			game.difficulty = false;
		}
	}
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

void ShootOff(bool a)
{
	pShoot.ShootOn = a;
}

void RecivePlayerDmg()
{
	player.life--;
}