#include "Player.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

Player player;

Game game;

extern float speed;

void InitPlayer()
{
	//vidas tambien tendrian que ser iniciadas aqui...
	player.pos.X = 10.f;
	player.pos.Y = game.H *0.5f;
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
	}

	if (FASG::IsKeyPressed('D'))
	{
		PlayerMovement direction = PlayerMovement::RIGHT;
		player.pos.X += player.speed * FASG::GetDeltaTime();
	}

	if (FASG::IsKeyPressed('S'))
	{
		PlayerMovement direction = PlayerMovement::DOWN;
		player.pos.Y += player.speed * FASG::GetDeltaTime();
	}

	if (FASG::IsKeyPressed('A'))
	{
		PlayerMovement direction = PlayerMovement::LEFT;
		player.pos.X -= player.speed * FASG::GetDeltaTime();

	}
}
	/* Main

		int incX = 0, incY = 0;

		if (FASG::IsKeyPressed('W'))
			incY = -1;
		if (FASG::IsKeyPressed('S'))
				incY = 1;
		if (FASG::IsKeyPressed('A'))
				incX = -1;
		if (FASG::IsKeyPressed('D'))
				incX = 1;
				DrawPlayer(incX, incY);
				
				
				
					void DrawPlayer(int incX, int incY)

		{
		float x, y;

		x = pX + incX * FASG::GetDeltaTime() * pS;
		y = pY + incY * FASG::GetDeltaTime() * pS;

		if (x >= W || x < 0 || y >= H || y < 0)
		{
			return;
		}

		pX = x;
		pY = y;

		FASG::WritePixelBuffer(pX, pY, FASG::EBackColor::LightWhite);
	
	*/




/*switch (PlayerMovement direction)
{
case PlayerMovement::RIGHT:
}*/