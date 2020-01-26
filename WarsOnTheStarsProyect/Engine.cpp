#include "Engine.h"
#include "FAriasSimpleGraphics.h"
#include "Player.h"
#include "Enemies.h"

//Poner fondo de color, usado en las palabras
void BackgroundWords(int initialX, int finalX, int Y)
{
	for (initialX; initialX <= finalX; initialX++)
	{
		FASG::WritePixelBuffer(initialX, Y, FASG::EBackColor::LightBlack);
	}
}

//Restar el tiempo a variables de CD
void TimeMinus(float& b)
{
	b -= FASG::GetDeltaTime();
}

//Sistema de Colisiones
void Colisions(std::string tag1, std::string tag2)
{
	//Obtener la cantidad de enemigos de cada tipo
	int EnemiesLit = envLitEnQuantity();
	int EnemiesMid = envMidEnQuantity();
	int EnemiesLar = envLarEnQuantity();



	/*Disparos - Enemigos*/

	//Disparo golpea a enemigos pequeños, se resetea el disparo
	for (int i = 0; i < EnemiesLit; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enLit" + i || tag2 == "ShootPlayer" && tag1 == "enLit" + i)
		{
			ReciveLitDmg(i);
			ShootOff(false);
		}
	}

	//Disparo golpea a enemigos medianos, se resetea el disparo
	for (int i = 0; i < EnemiesMid; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enMed" + i || tag2 == "ShootPlayer" && tag1 == "enMed" + i)
		{
			ReciveMidDmg(i);
			ShootOff(false);
		}
	}

	//Disparo reseteado al golpear a enemigos grandes, no reciben daño hasta fase final
	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enLarge" + i || tag2 == "ShootPlayer" && tag1 == "enLarge" + i)
		{
			ShootOff(false);
		}
	}

	//Disparo golpea a enemigos grandes, se resetea el disparo
	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enLargeFinal" + i || tag2 == "ShootPlayer" && tag1 == "enLargeFinal" + i)
		{
			ReciveLarDmg(i);
			ShootOff(false);
		}
	}

	//Disparo golpea al jefe final, se resetea el disparo
	if ((tag1 == "ShootPlayer" && tag2 == "FinalBoss") || (tag2 == "ShootPlayer" && tag1 == "FinalBoss"))
	{
		ReciveBossDmg();
		ShootOff(false);
	}



	/*Player - Enemigos*/

	for (int i = 0; i < EnemiesLit; i++)
	{
		//Enemigo toca a jugador, jugador recibe daño
		if ((tag1 == "Player" && tag2 == "enLit" + i) || (tag2 == "Player" && tag1 == "enLit" + i))
		{
			RecivePlayerDmg(false);
		}

		//Disparo enemigo golpea a jugador, se reinicia el disparo enemigo, recibe daño jugador
		if (tag1 == "Player" && tag2 == "ShootEnemieLit" + i || (tag2 == "Player" && tag1 == "ShootEnemieLit" + i) || (tag1 == "PlayerInMove" && tag2 == "ShootEnemieLit" + i) || (tag2 == "PlayerInMove" && tag1 == "ShootEnemieLit"))
		{
			RecivePlayerDmg(false);
			RestartShootEnLit(i);
		}
	}

	for (int a = 0; a < EnemiesMid; a++)
	{
		//Disparo enemigo golpea a jugador, se reinicia el disparo enemigo, recibe daño jugador
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
		}
	}

	for (int l = 0; l < EnemiesLar; l++)
	{
		if (((tag1 == "Player" && tag2 == "enLargeFinal" + l) || (tag2 == "Player" && tag1 == "enLargeFinal" + l)) || ((tag1 == "PlayerInMove" && tag2 == "enLargeFinal" + l) || (tag2 == "PlayerInMove" && tag1 == "enLargeFinal" + l)))
		{
			//Entra en este if cuando no deberia entrar
			//RecivePlayerDmg(true);
		}
	}

	//En caso de que golpee el laser del jefe al jugador
	if (((tag1 == "Player" && tag2 == "laser") || (tag2 == "Player" && tag1 == "laser")) || ((tag1 == "PlayerInMove" && tag2 == "laser") || (tag2 == "PlayerInMove" && tag1 == "laser")))
	{
		RecivePlayerDmg(false);
	}
}