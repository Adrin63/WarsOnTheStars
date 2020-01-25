#include "Engine.h"
#include "FAriasSimpleGraphics.h"
#include "Player.h"
#include "Enemies.h"

void BackgroundWords(int initialX, int finalX, int Y)
{
	for (initialX; initialX <= finalX; initialX++)
	{
		FASG::WritePixelBuffer(initialX, Y, FASG::EBackColor::LightBlack);
	}
}

void TimeMinus(float& b)
{
	b -= FASG::GetDeltaTime();
}

void Colisions(std::string tag1, std::string tag2)
{
	int EnemiesLit = envLitEnQuantity();
	int EnemiesMid = envMidEnQuantity();
	int EnemiesLar = envLarEnQuantity();

	//Disparos - Enemigos
	for (int i = 0; i < EnemiesLit; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enLit" + i || tag2 == "ShootPlayer" && tag1 == "enLit" + i)
		{
			ReciveLitDmg(i);
			ShootOff(false);
		}
	}

	for (int i = 0; i < EnemiesMid; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enMed" + i || tag2 == "ShootPlayer" && tag1 == "enMed" + i)
		{
			ReciveMidDmg(i);
			ShootOff(false);
		}
	}

	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enLarge" + i || tag2 == "ShootPlayer" && tag1 == "enLarge" + i)
		{
			ReciveLarDmg(i);
			ShootOff(false);
		}
	}

	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enLargeFinal" + i || tag2 == "ShootPlayer" && tag1 == "enLargeFinal" + i)
		{
			ReciveLarDmg(i);
			ShootOff(false);
		}
	}

	if ((tag1 == "ShootPlayer" && tag2 == "FinalBoss") || (tag2 == "ShootPlayer" && tag1 == "FinalBoss"))
	{
		ReciveBossDmg();
		ShootOff(false);
	}

	//Player - Enemigos
	for (int i = 0; i < EnemiesLit; i++)
	{
		if ((tag1 == "Player" && tag2 == "enLit" + i) || (tag2 == "Player" && tag1 == "enLit" + i))
		{
			RecivePlayerDmg(false);
		}

		if (tag1 == "Player" && tag2 == "ShootEnemieLit" + i || (tag2 == "Player" && tag1 == "ShootEnemieLit" + i) || (tag1 == "PlayerInMove" && tag2 == "ShootEnemieLit" + i) || (tag2 == "PlayerInMove" && tag1 == "ShootEnemieLit"))
		{
			RecivePlayerDmg(false);
			RestartShootEnLit(i);
		}
	}

	for (int a = 0; a < EnemiesMid; a++)
	{
		if ((tag1 == "Player" && tag2 == "ShootEnemieMid" + a) || (tag2 == "Player" && tag1 == "ShootEnemieMid" + a) || (tag1 == "PlayerInMove" && tag2 == "ShootEnemieMid" + a) || (tag2 == "PlayerInMove" && tag1 == "ShootEnemieMid" + a))
		{
			RecivePlayerDmg(false);
			RestartShootEnMid(a);
		}
	}

	for (int l = 0; l < EnemiesLar; l++)
	{
		if (((tag1 == "Player" && tag2 == "enLarge" + l) || (tag2 == "Player" && tag1 == "enLarge" + l)) || ((tag1 == "PlayerInMove" && tag2 == "enLarge" + l) || (tag2 == "PlayerInMove" && tag1 == "enLarge" + l)))
		{
			//Entra en este if cuando no deberia entrar
			//RecivePlayerDmg(true);
			//RestartShootEnMid(l);
		}
	}

	for (int l = 0; l < EnemiesLar; l++)
	{
		if (((tag1 == "Player" && tag2 == "laser") || (tag2 == "Player" && tag1 == "laser")) || ((tag1 == "PlayerInMove" && tag2 == "laser") || (tag2 == "PlayerInMove" && tag1 == "laser")))
		{
			RecivePlayerDmg(false);
		}
	}
}