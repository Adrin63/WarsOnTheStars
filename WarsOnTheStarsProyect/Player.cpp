#include "Player.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"
#include "Shoot.h"

Player player;

Game game;

Shoot pShoot;

//Disparo disparo;

extern float speed;

void InitPlayer()
{
	//vidas tambien tendrian que ser iniciadas aqui...
	player.pos.X = 10.f;
	player.pos.Y = game.H *0.5f;
	pShoot.posSh.X = player.pos.X + 7;
	pShoot.posSh.Y = player.pos.Y + 1;
	pShoot.speedSh = 20.f;
}

void DrawPlayer()
{
	//dibuja en pantalla el sprite del personaje en su X y Y

	FASG::WriteSpriteBuffer(player.pos.X, player.pos.Y, player.sprite);
}


void MovementPlayer()
{
	//Movimiento del jugador


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

		if (player.pos.X >= 292)
			player.pos.X = 292;
	}

	if (FASG::IsKeyPressed('S'))
	{
		PlayerMovement direction = PlayerMovement::DOWN;
		player.pos.Y += player.speed * FASG::GetDeltaTime();

		if (player.pos.Y >= 56)
			player.pos.Y = 56;
	}

	if (FASG::IsKeyPressed('A'))
	{
		PlayerMovement direction = PlayerMovement::LEFT;
		player.pos.X -= player.speed * FASG::GetDeltaTime();

		if (player.pos.X < 0)
			player.pos.X = 0;
	}

	if (FASG::IsKeyPressed('E'))
	{
		FASG::WriteSpriteBuffer(pShoot.posSh.X, pShoot.posSh.Y, FASG::Sprite("Shoot.txt"));
		pShoot.posSh.X += pShoot.speedSh * FASG::GetDeltaTime();
	}
}
	