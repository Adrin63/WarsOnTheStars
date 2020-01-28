#include "Engine.h"
#include "FAriasSimpleGraphics.h"
#include "Player.h"
#include "Enemies.h"
#include "SecondPlayer.h"
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
			ReciveLitDmg(i, 1);
			ShootOff(NULL, SHOOT);
		}
	}

	//Disparo golpea a enemigos medianos, se resetea el disparo
	for (int i = 0; i < EnemiesMid; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enMed" + i || tag2 == "ShootPlayer" && tag1 == "enMed" + i)
		{
			ReciveMidDmg(i, 1);
			ShootOff(NULL, SHOOT);
		}
	}

	//Disparo reseteado al golpear a enemigos grandes, no reciben daño hasta fase final
	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enLarge" + i || tag2 == "ShootPlayer" && tag1 == "enLarge" + i)
		{
			ShootOff(NULL, SHOOT);
		}
	}

	//Disparo golpea a enemigos grandes, se resetea el disparo
	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "ShootPlayer" && tag2 == "enLargeFinal" + i || tag2 == "ShootPlayer" && tag1 == "enLargeFinal" + i)
		{
			ReciveLarDmg(i, 1);
			ShootOff(NULL, SHOOT);
		}
	}

	//Disparo golpea al jefe final, se resetea el disparo
	if ((tag1 == "ShootPlayer" && tag2 == "FinalBoss") || (tag2 == "ShootPlayer" && tag1 == "FinalBoss"))
	{
		ReciveBossDmg(1);
		ShootOff(NULL, SHOOT);
	}



	/*Misiles - Enemigos*/



	/*Misil de arriba*/

	//Misil de arriba golpea a enemigos pequeños, se resetea el disparo
	for (int i = 0; i < EnemiesLit; i++)
	{
		if (tag1 == "MisilPlayerUp" && tag2 == "enLit" + i || tag2 == "MisilPlayerUp" && tag1 == "enLit" + i)
		{
			ReciveMidDmg(i, 5);
			ShootOff(true, MISIL);
		}
	}
	
	//Misil de arriba golpea a enemigos medianos, se resetea el disparo
	for (int i = 0; i < EnemiesMid; i++)
	{
		if (tag1 == "MisilPlayerUp" && tag2 == "enMed" + i || tag2 == "MisilPlayerUp" && tag1 == "enMed" + i)
		{
			ReciveMidDmg(i, 5);
			ShootOff(true, MISIL);
		}
	}

	//Misil de arriba reseteado al golpear a enemigos grandes, no reciben daño hasta fase final
	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "MisilPlayerUp" && tag2 == "enLarge" + i || tag2 == "MisilPlayerUp" && tag1 == "enLarge" + i)
		{
			ShootOff(true, MISIL);
		}
	}

	//Misil de arriba golpea a enemigos grandes, se resetea el disparo
	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "MisilPlayerUp" && tag2 == "enLargeFinal" + i || tag2 == "MisilPlayerUp" && tag1 == "enLargeFinal" + i)
		{
			ReciveLarDmg(i, 5);
			ShootOff(true, MISIL);
		}
	}

	//Misil de arriba golpea al jefe final, se resetea el disparo
	if ((tag1 == "MisilPlayerUp" && tag2 == "FinalBoss") || (tag2 == "MisilPlayerUp" && tag1 == "FinalBoss"))
	{
		ReciveBossDmg(5);
		ShootOff(true, MISIL);
	}



	/*Misil de abajo*/


	//Misil de abajo golpea a enemigos pequeños, se resetea el disparo
	for (int i = 0; i < EnemiesLit; i++)
	{
		if (tag1 == "MisilPlayerDown" && tag2 == "enLit" + i || tag2 == "MisilPlayerDown" && tag1 == "enLit" + i)
		{
			ReciveLitDmg(i, 5);
			ShootOff(false, MISIL);
		}
	}

	//Misil de abajo golpea a enemigos medianos, se resetea el disparo
	for (int i = 0; i < EnemiesMid; i++)
	{
		if (tag1 == "MisilPlayerDown" && tag2 == "enMed" + i || tag2 == "MisilPlayerDown" && tag1 == "enMed" + i)
		{
			ReciveMidDmg(i, 5);
			ShootOff(false, MISIL);
		}
	}

	//Misil de abajo reseteado al golpear a enemigos grandes, no reciben daño hasta fase final
	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "MisilPlayerDown" && tag2 == "enLarge" + i || tag2 == "MisilPlayerDown" && tag1 == "enLarge" + i)
		{
			ShootOff(false, MISIL);
		}
	}

	//Misil de abajo golpea a enemigos grandes, se resetea el disparo
	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "MisilPlayerDown" && tag2 == "enLargeFinal" + i || tag2 == "MisilPlayerDown" && tag1 == "enLargeFinal" + i)
		{
			ReciveLarDmg(i, 5);
			ShootOff(false, MISIL);
		}
	}

	//Misil de abajo golpea al jefe final, se resetea el disparo
	if ((tag1 == "MisilPlayerDown" && tag2 == "FinalBoss") || (tag2 == "MisilPlayerDown" && tag1 == "FinalBoss"))
	{
		ReciveBossDmg(5);
		ShootOff(false, MISIL);
	}


	/*DISPARO JUGADOR 2*/



	//Disparo del jugador 2 golpea a enemigos pequeños, se resetea el disparo
	for (int i = 0; i < EnemiesLit; i++)
	{
		if (tag1 == "ShootSecPlayer" && tag2 == "enLit" + i || tag2 == "ShootSecPlayer" && tag1 == "enLit" + i)
		{
			ReciveLitDmg(i, 2);
			ShootSecOff();
		}
	}

	//Disparo del jugador 2 golpea a enemigos medianos, se resetea el disparo
	for (int i = 0; i < EnemiesMid; i++)
	{
		if (tag1 == "ShootSecPlayer" && tag2 == "enMed" + i || tag2 == "ShootSecPlayer" && tag1 == "enMed" + i)
		{
			ReciveMidDmg(i, 2);
			ShootSecOff();
		}
	}

	//Disparo del jugador 2 reseteado al golpear a enemigos grandes, no reciben daño hasta fase final
	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "ShootSecPlayer" && tag2 == "enLarge" + i || tag2 == "ShootSecPlayer" && tag1 == "enLarge" + i)
		{
			ShootSecOff();
		}
	}

	//Disparo del jugador 2 golpea a enemigos grandes, se resetea el disparo
	for (int i = 0; i < EnemiesLar; i++)
	{
		if (tag1 == "ShootSecPlayer" && tag2 == "enLargeFinal" + i || tag2 == "ShootSecPlayer" && tag1 == "enLargeFinal" + i)
		{
			ReciveLarDmg(i, 2);
			ShootSecOff();
		}
	}

	//Disparo del jugador 2 golpea al jefe final, se resetea el disparo
	if ((tag1 == "ShootSecPlayer" && tag2 == "FinalBoss") || (tag2 == "ShootSecPlayer" && tag1 == "FinalBoss"))
	{
		ReciveBossDmg(2);
		ShootSecOff();
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
		if ((tag1 == "secPlayer" && tag2 == "ShootEnemieMid" + a) || (tag2 == "secPlayer" && tag1 == "ShootEnemieMid" + a) || (tag1 == "PlayerInMove" && tag2 == "ShootEnemieMid" + a) || (tag2 == "PlayerInMove" && tag1 == "ShootEnemieMid" + a))
		{
			RecivePlayerDmg(false);
			RestartShootEnMid(a);
		}
	}

	for (int l = 0; l < EnemiesLar; l++)
	{
		//Al pasar true hace 2 de daño
		if (((tag1 == "Player" && tag2 == "enLarge" + l) || (tag2 == "Player" && tag1 == "enLarge" + l)) || ((tag1 == "PlayerInMove" && tag2 == "enLarge" + l) || (tag2 == "PlayerInMove" && tag1 == "enLarge" + l)))
		{
			RecivePlayerDmg(true);
		}
	}

	for (int l = 0; l < EnemiesLar; l++)
	{
		//Al pasar true hace 2 de daño
		if (((tag1 == "Player" && tag2 == "enLargeFinal" + l) || (tag2 == "Player" && tag1 == "enLargeFinal" + l)) || ((tag1 == "PlayerInMove" && tag2 == "enLargeFinal" + l) || (tag2 == "PlayerInMove" && tag1 == "enLargeFinal" + l)))
		{
			RecivePlayerDmg(true);
		}
	}

	//En caso de que golpee el laser del jefe al jugador
	if (((tag1 == "Player" && tag2 == "laser") || (tag2 == "Player" && tag1 == "laser")) || ((tag1 == "PlayerInMove" && tag2 == "laser") || (tag2 == "PlayerInMove" && tag1 == "laser")))
	{
		RecivePlayerDmg(false);
	}



	/*SECOND PLAYER - ENEMIGOS*/



	for (int i = 0; i < EnemiesLit; i++)
	{
		//Enemigo toca a jugador, jugador recibe daño
		if ((tag1 == "secPlayer" && tag2 == "enLit" + i) || (tag2 == "secPlayer" && tag1 == "enLit" + i))
		{
			ReciveSecPlayerDmg();
		}

		//Disparo enemigo golpea a jugador, se reinicia el disparo enemigo, recibe daño jugador
		if (tag1 == "secPlayer" && tag2 == "ShootEnemieLit" + i || (tag2 == "secPlayer" && tag1 == "ShootEnemieLit" + i) || (tag1 == "secPlayerInMove" && tag2 == "ShootEnemieLit" + i) || (tag2 == "secPlayerInMove" && tag1 == "ShootEnemieLit"))
		{
			ReciveSecPlayerDmg();
			RestartShootEnLit(i);
		}
	}

	for (int a = 0; a < EnemiesMid; a++)
	{
		//Disparo enemigo golpea a jugador, se reinicia el disparo enemigo, recibe daño jugador
		if ((tag1 == "secPlayer" && tag2 == "ShootEnemieMid" + a) || (tag2 == "secPlayer" && tag1 == "ShootEnemieMid" + a) || (tag1 == "secPlayerInMove" && tag2 == "ShootEnemieMid" + a) || (tag2 == "secPlayerInMove" && tag1 == "ShootEnemieMid" + a))
		{
			ReciveSecPlayerDmg();
			RestartShootEnMid(a);
		}
	}

	for (int l = 0; l < EnemiesLar; l++)
	{
		//Al pasar true hace 2 de daño
		if (((tag1 == "secPlayer" && tag2 == "enLarge" + l) || (tag2 == "secPlayer" && tag1 == "enLarge" + l)) || ((tag1 == "secPlayerInMove" && tag2 == "enLarge" + l) || (tag2 == "secPlayerInMove" && tag1 == "enLarge" + l)))
		{
			ReciveSecPlayerDmg();
		}
	}

	for (int l = 0; l < EnemiesLar; l++)
	{
		//Al pasar true hace 2 de daño
		if (((tag1 == "secPlayer" && tag2 == "enLargeFinal" + l) || (tag2 == "secPlayer" && tag1 == "enLargeFinal" + l)) || ((tag1 == "secPlayerInMove" && tag2 == "enLargeFinal" + l) || (tag2 == "secPlayerInMove" && tag1 == "enLargeFinal" + l)))
		{
			ReciveSecPlayerDmg();
		}
	}

	//En caso de que golpee el laser del jefe al jugador
	if (((tag1 == "secPlayer" && tag2 == "laser") || (tag2 == "secPlayer" && tag1 == "laser")) || ((tag1 == "secPlayerInMove" && tag2 == "laser") || (tag2 == "secPlayerInMove" && tag1 == "laser")))
	{
		ReciveSecPlayerDmg();
	}
}