#include "Player.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"
#include <conio.h>
#include "Difficulty.h"

//Struct del jugador (vidas, velocidad y sprite)
Player player;

//Enum para la dirección del jugador
PlayerMovement direction;

//Variables de game para determinar el punto donde estas del juego
Game game;

//Struct de lOS disparoS del jugador
ShootP pShoot, pMisilUp, pMisilDown;

//Enum para la dificultad del juego
Diff difficult;



//Tiempo entre hits al jugador
float const coolDownLife = 1.f;
float CDLife = coolDownLife;
bool hitOn = true;

//Inicia el jugador
void InitPlayer()
{
	//Inicialización de los sprites del jugador
	player.sprite.LoadSprite("Player.txt");
	player.spriteInMove.LoadSprite("Player_Right.txt");
	FASG::Sprite::AddToCollisionSystem(player.sprite, "Player");
	FASG::Sprite::AddToCollisionSystem(player.spriteInMove, "PlayerInMove");

	//Inicialización de la posición
	player.spriteInMove.Location.x = -40;
	player.spriteInMove.Location.y = -40;

	player.sprite.Location.x = 10.f;
	player.sprite.Location.y = game.H * 0.5f;

	//Inicialización del disparo
	pShoot.shootPlayer.LoadSprite("Shoot.txt");
	FASG::Sprite::AddToCollisionSystem(pShoot.shootPlayer, "ShootPlayer");
	pShoot.speedSh = 300.f;
	pShoot.ShootOn = false;
	pShoot.type = ShootType::SHOOT;

	//Inicialización de los misiles
	pMisilUp.shootPlayer.LoadSprite("Misil.txt");
	FASG::Sprite::AddToCollisionSystem(pMisilUp.shootPlayer, "MisilPlayerUp");
	pMisilUp.speedSh = 75.f;
	pMisilUp.ShootOn = false;
	pMisilUp.type = ShootType::MISIL;

	pMisilDown.shootPlayer.LoadSprite("Misil.txt");
	FASG::Sprite::AddToCollisionSystem(pMisilDown.shootPlayer, "MisilPlayerDown");
	pMisilDown.speedSh = pMisilUp.speedSh;
	pMisilDown.ShootOn = false;
	pMisilDown.type = ShootType::MISIL;

	//en función de la dificultad, mas vidas o menos
	difficult = envDifficulty();

	switch (difficult)
	{
	case INMORTAL:
		player.life = 9999999;
		break;
	case NORMAL:
		player.life = 5;
		break;
	case ONE:
		player.life = 1;
		break;
	}
}

//Dibuja el jugador
void DrawPlayer()
{
	//Switch para mostrar en pantalla las vidas que tienes
	switch (difficult)
	{	
	case INMORTAL:
		//en caso de ser inmortal no sale que tiene vida
		break;
	default:

		//en caso de elegir 1 vida o normal, muestra HP y pone los puntos correspondientes a la vida
		FASG::WriteStringBuffer(3, 2, "HP:", FASG::EForeColor::LightWhite);

		for (int a = 0; a < player.life; a++)
		{
			FASG::WritePixelBuffer(7 + a + a, 2, FASG::EBackColor::LightWhite);
		}
	}



	//If que comprueba si esta vivo el jugador, en caso de no estarlo, salir del bucle y poner la pantalla de muerte
	if (player.life > 0)
	{
		//En función de la dirección del jugador, se muestra un sprite u otro
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
		game.difficulty = false;
		game.win = false;
		game.executable = true;
	}
}

//Movimiento del jugador
void MovementPlayer()
{
	//En caso de no moverse, el jugador se pone quieto
	direction = PlayerMovement::STILL;

	//Tiempo para poder recibir otro golpe
	if (!hitOn)
		TimeMinus(CDLife);

	if (CDLife <= 0)
	{
		CDLife = coolDownLife;
		hitOn = true;
	}



	//Controles de movimiento y limitaciones para no salir del mapa
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

		if (player.sprite.Location.x >= 220)
			player.sprite.Location.x = 220;
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

		if (player.sprite.Location.x < -2)
			player.sprite.Location.x = -2;
	}

	/*DISPARO NORMAL*/



	//Inicializar cada iteración el disparo en la posición del jugador
	if (!pShoot.ShootOn)
	{
		pShoot.shootPlayer.Location.x = player.sprite.Location.x + 5;
		pShoot.shootPlayer.Location.y = player.sprite.Location.y + 2;
	}

	//El disparo sale del jugador en caso de pulsar la J
	if (FASG::IsKeyPressed('J'))
	{
		pShoot.ShootOn = true;
	}

	//Se activa el disparo
	if (pShoot.ShootOn)
	{
		ShootPlayer(SHOOT, NULL);
	}


	/*MISIL*/



	if (!pMisilUp.ShootOn)
	{
		pMisilUp.shootPlayer.Location.x = player.sprite.Location.x + 12;
		pMisilUp.shootPlayer.Location.y = player.sprite.Location.y + 1;
	}

	if (!pMisilDown.ShootOn)
	{
		pMisilDown.shootPlayer.Location.x = player.sprite.Location.x + 12;
		pMisilDown.shootPlayer.Location.y = player.sprite.Location.y + 3;
	}

	//El MISIL sale del jugador en caso de pulsar la k
	if (FASG::IsKeyPressed('K'))
	{
		pMisilUp.ShootOn = true;
		pMisilDown.ShootOn = true;
	}

	if (pMisilUp.ShootOn)
	{
		ShootPlayer(MISIL, true);
	}

	if (pMisilDown.ShootOn)
	{
		ShootPlayer(MISIL, false);
	}
	//Botón de pausa
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

//Disparo del jugador
void ShootPlayer(ShootType a, bool b)
{
	switch (a)
	{
	case MISIL:
		if (b)
		{
			FASG::WriteSpriteBuffer(pMisilUp.shootPlayer.Location.x, pMisilUp.shootPlayer.Location.y, pMisilUp.shootPlayer);
			pMisilUp.shootPlayer.Location.x += pMisilUp.speedSh * FASG::GetDeltaTime();
			
			if (pMisilUp.shootPlayer.Location.x >= 300)
			{
				pMisilUp.ShootOn = false;
			}
		}
		else
		{
			FASG::WriteSpriteBuffer(pMisilDown.shootPlayer.Location.x, pMisilDown.shootPlayer.Location.y, pMisilDown.shootPlayer);
			pMisilDown.shootPlayer.Location.x += pMisilDown.speedSh * FASG::GetDeltaTime();



			if (pMisilDown.shootPlayer.Location.x >= 300)
			{
				pMisilDown.ShootOn = false;
			}
		}
		break;

	case SHOOT:
		FASG::WriteSpriteBuffer(pShoot.shootPlayer.Location.x, pShoot.shootPlayer.Location.y, pShoot.shootPlayer);
		pShoot.shootPlayer.Location.x += pShoot.speedSh * FASG::GetDeltaTime();

		if (pShoot.shootPlayer.Location.x >= 300)
		{
			pShoot.ShootOn = false;
		}
		break;
	}
}

//Resetea disparo en caso de golpear a enemigo
void ShootOff(bool a, ShootType b)
{
	switch (b)
	{
	case MISIL:
		if (a)
		{
			pMisilUp.ShootOn = false;
		}
		else
		{
			pMisilDown.ShootOn = false;
		}
	case SHOOT:
		pShoot.ShootOn = false;
	}

	
}



//Recibe daño el jugador, y en función si te da el enemigo grande o no te hace 1 o 2 de daño
void RecivePlayerDmg(bool dmg)
{
	//Si no ha pasado el tiempo entre golpes, no recibe daño el jugador
	if (hitOn)
	{
		switch (dmg)
		{
		case true:
			player.life -= 2;
			break;
		case false:
			player.life--;
			break;
		}
		hitOn = false;
	}
}