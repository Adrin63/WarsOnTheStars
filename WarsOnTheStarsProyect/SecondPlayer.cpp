#include "SecondPlayer.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"
#include "Difficulty.h"

//Variables de game para determinar el punto donde estas del juego
extern Game game;

//Segundo player
SecPlayer secPlayer;

//Dificultad del juego
Diff diffGame;

//Direccion del segundo player
SecPlayerMovement secDirection;

//Indica si hay 2 jugadores
QuantityPlayers secPlayerOn;

//Disparo del segundo player
ShootSecP secpShoot;

//Tiene coolDown entre golpes
float const coolDownLifeSec = 1.f;
float CDLifeSec = coolDownLifeSec;
bool hitOnSec = true;

void InitSecPlayer()
{
	//Inicia los sprites
	secPlayer.sprite.LoadSprite("secPlayer.txt");
	FASG::Sprite::AddToCollisionSystem(secPlayer.sprite, "secPlayer");

	secPlayer.spriteInMove.LoadSprite("secPlayerRight.txt");
	FASG::Sprite::AddToCollisionSystem(secPlayer.spriteInMove, "secPlayerInMove");

	//vendria el switch en caso de que este o no en pantalla
	secPlayer.spriteInMove.Location.x = -80;
	secPlayer.spriteInMove.Location.y = -80;

	secPlayer.speed = 50.f;

	//Inicialización del disparo del segundo player
	secpShoot.shootPlayer.LoadSprite("secShoot.txt");
	FASG::Sprite::AddToCollisionSystem(secpShoot.shootPlayer, "ShootSecPlayer");
	secpShoot.speedSh = 60.f;
	secpShoot.ShootOn = false;

	secPlayerOn = envQuantityPlayers();

	//En funcion de si hay 2 jugadores se pone en una posicion u otra
	switch (secPlayerOn)
	{
	case TWOPLAYERS:
		secPlayer.sprite.Location.x = 30.f;
		secPlayer.sprite.Location.y = game.H * 0.66f;
		break;
	case ONEPLAYER:
		secPlayer.sprite.Location.x = -100;
		secPlayer.sprite.Location.y = -100;
		break;
	}


	diffGame = envDifficulty();

	//En funcion de la dificultad tiene mas o menos vidas
	switch (diffGame)
	{
	case INMORTAL:
		secPlayer.life = 9999999;
		break;
	case NORMAL:
		secPlayer.life = 2;
		break;
	case ONE:
		secPlayer.life = 1;
		break;
	}
	

}

void DrawSecPlayer()
{
	if (secPlayerOn == TWOPLAYERS)

	{	//En caso de que haya 2 jugadores y su dificultad muestra o no la barra de vida y dibuja al jugador
		switch (diffGame)
		{
		case INMORTAL:
			switch (secDirection)
			{
			case SecPlayerMovement::secRIGHT:
				FASG::WriteSpriteBuffer(secPlayer.sprite.Location.x, secPlayer.sprite.Location.y, secPlayer.spriteInMove);
				break;

			default:
				FASG::WriteSpriteBuffer(secPlayer.sprite.Location.x, secPlayer.sprite.Location.y, secPlayer.sprite);
			}
			break;
		default:

			FASG::WriteStringBuffer(3, 4, "HP J2:", FASG::EForeColor::LightWhite);

			if (secPlayer.life > 0)
			{
				for (int a = 0; a < secPlayer.life; a++)
				{
					FASG::WritePixelBuffer(10 + a + a, 4, FASG::EBackColor::Cyan);
				}

				//En función de la dirección del jugador, se muestra un sprite u otro
				switch (secDirection)
				{
				case SecPlayerMovement::secRIGHT:
					FASG::WriteSpriteBuffer(secPlayer.sprite.Location.x, secPlayer.sprite.Location.y, secPlayer.spriteInMove);
					break;

				default:
					FASG::WriteSpriteBuffer(secPlayer.sprite.Location.x, secPlayer.sprite.Location.y, secPlayer.sprite);
				}
				
			}
			else
			{
				FASG::WriteStringBuffer(10, 4, "DEAD", FASG::EForeColor::LightWhite);
				secPlayer.sprite.Location.x = -100;
				secPlayer.sprite.Location.y = -100;
			}
			break;
		}
	}
}

void MovementSecPlayer()
{
	//Solo se dibuja y mueve si esta vivo
	if (secPlayer.life > 0)
	{
		secDirection = SecPlayerMovement::secSTILL;

		//CD entre golpes
		if (!hitOnSec)
			TimeMinus(CDLifeSec);

		if (CDLifeSec <= 0)
		{
			CDLifeSec = coolDownLifeSec;
			hitOnSec = true;
		}

		//Controles de movimiento y limitaciones para no salir del mapa
		if (FASG::IsKeyPressed('I'))
		{
			secPlayer.sprite.Location.y -= secPlayer.speed * FASG::GetDeltaTime();

			if (secPlayer.sprite.Location.y < 0)
				secPlayer.sprite.Location.y = 0;
		}

		if (FASG::IsKeyPressed('L'))
		{
			secDirection = SecPlayerMovement::secRIGHT;
			secPlayer.sprite.Location.x += secPlayer.speed * FASG::GetDeltaTime();

			if (secPlayer.sprite.Location.x >= 220)
				secPlayer.sprite.Location.x = 220;
		}

		if (FASG::IsKeyPressed('K'))
		{
			secPlayer.sprite.Location.y += secPlayer.speed * FASG::GetDeltaTime();

			if (secPlayer.sprite.Location.y >= 56)
				secPlayer.sprite.Location.y = 56;
		}

		//Disparo, funciona igual que el del player original
		if (FASG::IsKeyPressed('J'))
		{
			secPlayer.sprite.Location.x -= secPlayer.speed * FASG::GetDeltaTime();

			if (secPlayer.sprite.Location.x < -2)
				secPlayer.sprite.Location.x = -2;
		}

		if (!secpShoot.ShootOn)
		{
			secpShoot.shootPlayer.Location.x = secPlayer.sprite.Location.x + 6;
			secpShoot.shootPlayer.Location.y = secPlayer.sprite.Location.y;
		}

		if (FASG::IsKeyPressed('9'))
		{
			secpShoot.ShootOn = true;
		}

		if (secpShoot.ShootOn)
		{
			ShootSecondPlayer();
		}
	}
}

void ShootSecondPlayer()
{
	FASG::WriteSpriteBuffer(secpShoot.shootPlayer.Location.x, secpShoot.shootPlayer.Location.y, secpShoot.shootPlayer);
	secpShoot.shootPlayer.Location.x += secpShoot.speedSh * FASG::GetDeltaTime();

	if (secpShoot.shootPlayer.Location.x >= 300)
	{
		secpShoot.ShootOn = false;
	}
}

void ShootSecOff()
{
	secpShoot.ShootOn = false;
}

void ReciveSecPlayerDmg()
{
	if (hitOnSec)
	{
		secPlayer.life--;
		hitOnSec = false;
	}
}
