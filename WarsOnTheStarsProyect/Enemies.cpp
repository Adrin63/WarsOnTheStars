#include "Enemies.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"
#include "Stars.h"
#include "Difficulty.h"

//Variables de game para determinar el punto donde estas del juego
extern Game game;

//Cantidad enemigos de cada tipo
int const EnemiesLit = 4, EnemiesMed = 3, EnemiesLar = 2;

//Determina si va hacia arriba o hacia abajo en los pequeños y el boss
enemiMovement movEnemie = enemiMovement::enUP, movBoss;

//Cantidad de jugadores
QuantityPlayers playersInScreen;

//Enemigos y Disparos de enemigos
Enemie enemiesLittle[EnemiesLit], enemiesMedium[EnemiesMed], enemiesLarge[EnemiesLar], finalBoss;
ShootE shootEnemieLittle[EnemiesLit], shootEnemieMid[EnemiesMed];


/*COMBATE*/


//Tiempo entre acciones de los enemigos, pequeños y medianos en moverse arriba o abajo, los grandes embestir
float const MovementCDLittle = 0.85f, MovementCDMedium = 1.25f, MovementCDLarge = 3.f;
float CDLittle = MovementCDLittle, CDMedium = MovementCDMedium, CDLarge = MovementCDLarge;

//Movimiento hacia arriba y hacia abajo de los enemigos pequeños y medianos
int contador = 0;



/*ENEMIGOS GRANDES*/


//Guarda si los enemigos grandes se han ido de pantalla
bool allAway = false;

//Tiempo entre embestidas
float timeUntilAppear = 2.f;
float CDUntilAppear = timeUntilAppear;

//Reinicia la posición de los Enemigos grandes durante el combate
bool RestartLarge[EnemiesLar];


//Variables para saber cuando mueren todos los de un mismo tipo
int DeadLit = 0, DeadMid = 0, DeadLar = 0;
bool allDeadLit = false, allDeadMid = false;




/*PREPARACION COMBATE FINAL*/

//Canción del combate final
FASG::WAVESound finalBossSong;

//Activa la musica cuando se van los enemigos grandes, dejando paso al combate final
bool badTime = false;

//Tiempos de espera de los enemigos grandes y el jefe para la fase final
float CDUntilFinalStage = 7.8f;
float CDStartFinalStage = 5.f;

//Determinan el principio de la batalla final
bool finalStageStart = false, start = true;




/*COMBATE FINAL*/




/*LASER*/


//Sprite del Laser del Boss
Laser laserBoss;

//Mientras esta en true se lanza el laser del jefe final
bool laser = false;

//Tiempo de laser en pantalla
float const timeLaser = 2.5f;
float CDlaser = timeLaser;

//Contador para saber si tiene que disparar el laser
int cont = 0;


/*ACCIONES EN LA BATALLA FINAL*/


//Movimiento hacia arriba y hacia abajo del Boss
int contadorBoss = 0;

//Tiempo entre ataques del Boss
float const cooldownAttacks = 0.5f;
float CDBoss = cooldownAttacks;

//Tiempo de espera entre embestidas de los enemigos Grandes en la batalla final
float const coolDownOnLastStage = 1.f;
float CDLarOnLastStage = coolDownOnLastStage;

//Inicialización de los Enemigos
void InitEnemies()
{
	//cantidad jugadores
	playersInScreen = envQuantityPlayers();

	//Cargar la canción
	finalBossSong.LoadSound("BadTime.wav");

	/*Reinicializar todas las variables*/

	movEnemie = enemiMovement::enUP;

	CDLittle = MovementCDLittle, CDMedium = MovementCDMedium, CDLarge = MovementCDLarge;
	
	contador = 0;

	allAway = false;
	CDUntilAppear = timeUntilAppear;

	DeadLit = 0, DeadMid = 0, DeadLar = 0;
	allDeadLit = false, allDeadMid = false;

	badTime = false;

	CDUntilFinalStage = 7.8f;
	CDStartFinalStage = 5.f;

	finalStageStart = false, start = true;
	
	movBoss = enemiMovement::enUP;
	laser = false;
	CDlaser = timeLaser;
	cont = 0;

	contadorBoss = 0;

	CDBoss = cooldownAttacks;
	CDLarOnLastStage = coolDownOnLastStage;

	/*                                */

	//Inizialización del laser
	laserBoss.sprite.LoadSprite("EnemieLaser.txt");
	FASG::Sprite::AddToCollisionSystem(laserBoss.sprite, "laser");
	laserBoss.sprite.Location.x = -400;
	laserBoss.sprite.Location.y = 28;


	//*Inizialización de los enemigos pequeños*/


	//La posición Y
	enemiesLittle[0].sprite.Location.y = 10;
	enemiesLittle[1].sprite.Location.y = 22;
	enemiesLittle[2].sprite.Location.y = 34;
	enemiesLittle[3].sprite.Location.y = 46;

	for (int i = 0; i < EnemiesLit; i++)
	{
		//La vida y el sprite
		switch (playersInScreen)
		{
		case TWOPLAYERS:
			enemiesLittle[i].vida = 7;
			break;
		case ONEPLAYER:
			enemiesLittle[i].vida = 3;
			break;
		}
		enemiesLittle[i].sprite.LoadSprite("EnemieLittle.txt");
		FASG::Sprite::AddToCollisionSystem(enemiesLittle[i].sprite, "enLit" + i);

		//La posición X
		enemiesLittle[i].sprite.Location.x = 200;


		//Inicialización del Disparo
		shootEnemieLittle[i].sprite.LoadSprite("ShootEnemieLit.txt");
		shootEnemieLittle[i].onOff = true;
		shootEnemieLittle[i].CDShoot = rand() % 5 + 1;
		shootEnemieLittle[i].shootEnemieSpeed = 80.f;
		FASG::Sprite::AddToCollisionSystem(shootEnemieLittle[i].sprite, "ShootEnemieLit" + i);
	}


	/*Inizialización de los enemigos medianos*/


	//La posición Y
	enemiesMedium[0].sprite.Location.y = 7;
	enemiesMedium[1].sprite.Location.y = 26;
	enemiesMedium[2].sprite.Location.y = 45;

	for (int l = 0; l < EnemiesMed; l++)
	{
		//La vida y el sprite
		switch (playersInScreen)
		{
		case TWOPLAYERS:
			enemiesMedium[l].vida = 15;
			break;
		case ONEPLAYER:
			enemiesMedium[l].vida = 10;
			break;
		}
		
		enemiesMedium[l].sprite.LoadSprite("EnemieMedium.txt");
		FASG::Sprite::AddToCollisionSystem(enemiesMedium[l].sprite, "enMed" + l);

		//La posición X
		enemiesMedium[l].sprite.Location.x = 225;


		//Inicialización del Disparo
		shootEnemieMid[l].sprite.LoadSprite("ShootEnemieMid.txt");
		shootEnemieMid[l].onOff = true;
		shootEnemieMid[l].CDShoot = rand() % 5 + 3;
		shootEnemieMid[l].shootEnemieSpeed = 40.f;
		FASG::Sprite::AddToCollisionSystem(shootEnemieMid[l].sprite, "ShootEnemieMid" + l);
	}


	/*Inizialización de los enemigos grandes*/


	//La posición Y
	enemiesLarge[0].sprite.Location.y = 3;
	enemiesLarge[1].sprite.Location.y = 41;
	
	for (int j = 0; j < EnemiesLar; j++)
	{
		//La vida y el sprite
		enemiesLarge[j].vida = 9999999;
		enemiesLarge[j].sprite.LoadSprite("EnemieLargeShield.txt");
		FASG::Sprite::AddToCollisionSystem(enemiesLarge[j].sprite, "enLarge" + j);

		//La posición X
		enemiesLarge[j].sprite.Location.x = 260;
	}


	/*Inizialización del Boss*/


	//La vida y el sprite
	finalBoss.vida = 80;
	finalBoss.sprite.LoadSprite("FinalBoss.txt");
	FASG::Sprite::AddToCollisionSystem(finalBoss.sprite, "FinalBoss");

	//La posición X y Y
	finalBoss.sprite.Location.y = 22;
	finalBoss.sprite.Location.x = 305;
}

//Juego
void DrawEnemies()
{
	//Tiempo entre acciones de los enemigos
	TimeMinus(CDLittle);
	TimeMinus(CDMedium);
	TimeMinus(CDLarge);

	//Disparos de los enemigos
	EnemiesShoots();

	//Movimiento de los enemigos pequeños
	MovementLittle();

	//Movimiento de los enemigos medianos
	MovementMiddle();

	//Movimiento de los enemigos grandes mientras no comience la preparación a la batalla final
	if (!(allDeadLit && allDeadMid))
	{
		MovementLarge();
	}

	//Musica del combate final, comienza en la preparación
	if (badTime)
	{
		finalBossSong.Play();
	}

	//Preparación para el combate final
	if ((allDeadLit && allDeadMid) && (!finalStageStart))
	{
		DrawStars(false);
		FinalStagePreparation();
	}

	//Combate final
	if (finalStageStart)
	{
		TimeMinus(CDStartFinalStage);

		if (CDStartFinalStage <= 0)
		{
			FinalBossMovements();
			FinalBossMovementsLar();
		}
	}

	//Dibuja en pantalla los enemigos grandes
	for (int draw = 0; draw < EnemiesLar; draw++)
	{
		if (!game.end && enemiesLarge[draw].vida > 0)
		{
			FASG::WriteSpriteBuffer(enemiesLarge[draw].sprite.Location.x, enemiesLarge[draw].sprite.Location.y, enemiesLarge[draw].sprite);
		}
		else
		{
			//En caso de morir, los pone fuera de pantalla
			enemiesLarge[draw].sprite.Location.x = -20;
		}
	}

	//Barra de vida del jefe final y Nombre
	if (CDStartFinalStage <= 0)
	{
		for (int draw = 120; draw < 120+finalBoss.vida; draw++)
		{
			FASG::WritePixelBuffer(draw, 4, FASG::EBackColor::LightYellow);
			FASG::WritePixelBuffer(draw, 5, FASG::EBackColor::LightYellow);
		}
	}

	//Dibuja en pantalla al jefe final
	if (!game.end && finalBoss.vida > 0)
	{
		FASG::WriteSpriteBuffer(finalBoss.sprite.Location.x, finalBoss.sprite.Location.y, finalBoss.sprite);
	}

	//Cuando muere el jefe final, pantalla de victoria
	if(!game.end && finalBoss.vida <= 0)
	{
		game.gameplay = false;
		game.difficulty = false;
		game.end = false;
		game.howToPlay = false;
		game.win = true;
	}
}



/*MOVIMIENTO DE LOS ENEMIGOS*/



//Movimiento de los enemigos pequeños
void MovementLittle()
{
	/*Se modifica la posición del enemigo en función haya subido las veces indicadas y el tiempo CDLittle llegue a 0,
	en caso de llegar a este si va hacia arriba, cambia hacia abajo. Cada ciertos movimientos se mueve uno a la izquierda*/

	if (CDLittle <= 0)
	{
		//Se mueven hacia arriba/abajo
		for (int i = 0; i < EnemiesLit; i++)
		{
			switch (movEnemie)
			{
			case enUP:
				enemiesLittle[i].sprite.Location.y -= 2;
				break;
			case enDOWN:
				enemiesLittle[i].sprite.Location.y += 2;
				break;
			}
		}

		//Cuenta las veces que se ha movido
		switch (movEnemie)
		{
		case enUP:
			contador++;
			break;
		case enDOWN:
			contador--;
			break;
		}

		//cambia de sentido y mueve a la izquierda al enemigo
		switch (contador)
		{
		case 3:
			movEnemie = enemiMovement::enDOWN;
			for (int i = 0; i < EnemiesLit; i++)
				enemiesLittle[i].sprite.Location.x -= 4;

			break;
		case 0:
			movEnemie = enemiMovement::enUP;

			for (int i = 0; i < EnemiesLit; i++)
				enemiesLittle[i].sprite.Location.x -= 4;
			break;
		}

		CDLittle = MovementCDLittle;
	}

	DeadLit = 0;

	//Dibuja los enemigos pequeños en pantalla
	for (int draw = 0; draw < EnemiesLit; draw++)
	{
		if (enemiesLittle[draw].vida > 0 && (!game.end))
		{
			FASG::WriteSpriteBuffer(enemiesLittle[draw].sprite.Location.x, enemiesLittle[draw].sprite.Location.y, enemiesLittle[draw].sprite);
		}
		else
		{
			DeadLit++;
			enemiesLittle[draw].sprite.Location.x = -10;
		}
	}

	//Si todos estan muertos los enemigos pequeños, se activa allDeadLit
	if (DeadLit >= EnemiesLit)
	{
		allDeadLit = true;
	}
}

//Movimiento de los enemigos medianos
void MovementMiddle()
{
	//Funciona el sistema igual que en los enemigos pequeños, pero CDMedium es mayor
	if (CDMedium <= 0)
	{
		for (int i = 0; i < EnemiesMed; i++)
		{
			switch (movEnemie)
			{
			case enUP:
				enemiesMedium[i].sprite.Location.y -= 2;
				break;
			case enDOWN:
				enemiesMedium[i].sprite.Location.y += 2;
				break;
			}
		}

		switch (movEnemie)
		{
		case enUP:
			contador++;
			break;
		case enDOWN:
			contador--;
			break;
		}

		switch (contador)
		{
		case 3:
			movEnemie = enemiMovement::enDOWN;
			for (int i = 0; i < EnemiesMed; i++)
				enemiesMedium[i].sprite.Location.x -= 4;

			break;
		case 0:
			movEnemie = enemiMovement::enUP;

			for (int i = 0; i < EnemiesMed; i++)
				enemiesMedium[i].sprite.Location.x -= 4;
			break;
		}

		CDMedium = MovementCDMedium;
	}

	DeadMid = 0;

	//Dibuja los enemigos medianos en pantalla
	for (int draw = 0; draw < EnemiesMed; draw++)
	{
		if (enemiesMedium[draw].vida > 0 && (!game.end))
		{
			FASG::WriteSpriteBuffer(enemiesMedium[draw].sprite.Location.x, enemiesMedium[draw].sprite.Location.y, enemiesMedium[draw].sprite);
		}
		else
		{
			DeadMid++;
			enemiesMedium[draw].sprite.Location.x = -10;
		}
	}

	//Si todos los enemigos medianos estan muertos, se activa allDeadMid
	if (DeadMid == EnemiesMed)
	{
		allDeadMid = true;
	}
}

//Movimiento de los enemigos grandes
void MovementLarge()
{
	if (!allAway)
	{
		//Se mueven hasta la izquierda hasta que salen de pantalla, se activa allAway cuando esto pasa
		if (CDLarge <= 0)
		{
			for (int i = 0; i < EnemiesLar; i++)
			{
				enemiesLarge[i].sprite.Location.x -= 2;

				if (enemiesLarge[i].sprite.Location.x <= -24)
				{
					RestartLarge[i] = true;
					allAway = true;
				}
			}			
		}
	}

	//Se espera a que el CD llegue a 0 para volverlos a colocar a la derecha y colocarlos en una X en concreto, para volver a poner AllAway desactivado
	if (allAway)
	{
		TimeMinus(CDUntilAppear);

		if (CDUntilAppear <= 0)
		{
			FromRightLarg(true);
		}
	}
}

/*Coloca a los enemigos grandes a la derecha, fuera de la pantalla, los pone en 260
y en función si es el combate normal o la preparación del combate final, va mas rapido o mas lento*/
void FromRightLarg(bool a)
{
	for (int i = 0; i < EnemiesLar; i++)
	{
		//Los pone en 305 y se pone en false para que no lo vuelva a hacer
		if (RestartLarge[i])
		{
			enemiesLarge[i].sprite.Location.x = 305;
			RestartLarge[i] = false;
		}

		//En función del momento de la partida va a diferente velocidad
		switch (a)
		{
		case true:
			enemiesLarge[i].sprite.Location.x--;
			break;
		case false:
			enemiesLarge[i].sprite.Location.x -= 0.4f;
			break;
		}

		//Cuando llega a 260 desactiva la función
		if (enemiesLarge[i].sprite.Location.x <= 260)
		{
			enemiesLarge[i].sprite.Location.x = 260;

			switch (a)
			{
			case true:
				RestartLarge[i] = true;
				break;
			case false:
				finalStageStart = true;
				break;
			}

			allAway = false;
			CDUntilAppear = timeUntilAppear;
			CDLarge = MovementCDLarge;
		}
	}
}



/*PREPARACIÓN DEL COMBATE FINAL*/



//Preparación del combate final
void FinalStagePreparation()
{
	//Asigna una vida mas alcanzable a los enemigos grandes
	for (int j = 0; j < EnemiesLar; j++)
	{
		switch (playersInScreen)
		{
		case TWOPLAYERS:
			enemiesLarge[j].vida = 120;
			break;
		case ONEPLAYER:
			enemiesLarge[j].vida = 80;
			break;
		}	
	}
	
	//Para que no desaparezcan espontaneamente, mueve los enemigos grandes fuera de pantalla
	if (CDUntilFinalStage > 0)
	{
		AllLeftLarg();
	}
	
	if (CDUntilFinalStage <= 0)
	{
		for (int i = 0; i < EnemiesLar; i++)
		{
			//Cambia el sprite de los enemigos grandes a uno que no tienen escudo
			enemiesLarge[i].sprite.LoadSprite("EnemieLarge.txt");
			FASG::Sprite::AddToCollisionSystem(enemiesLarge[i].sprite, "enLargeFinal" + i);
		}

		//Posiciona a los enemigos grandes para el inicio del combate final
		FromRightLarg(false);
	}
}

//Movimiento de los enemigos grandes para iniciar la preparación de la fase final
void AllLeftLarg()
{
	//se ejecuta un ultimo movimiento para salir de pantalla para que quede organica su desaparición
	int aux = 0;

	for (int i = 0; i < EnemiesLar; i++)
	{
		enemiesLarge[i].sprite.Location.x -= 2;

		if (enemiesLarge[i].sprite.Location.x <= -24)
		{
			aux++;
		}
	}
	if (aux == 2)
	{
		badTime = true;
		TimeMinus(CDUntilFinalStage);
	}
}



/*COMBATE FINAL*/



//Movimientos del enemigo final
void FinalBossMovements()
{
	//Al principio del combate lo coloca delante de los enemigos grandes
	if (start)
	{
		movBoss = enemiMovement::enUP;
		finalBoss.sprite.Location.x -= 0.4;
		if (finalBoss.sprite.Location.x <= 240)
			start = false;
	}

	//Mientras no dispara el laser
	if (!laser)
	{
		if (!start)
		{
			//Resta el tiempo para el siguiente ataque del Boss
			TimeMinus(CDBoss);

			if (CDBoss <= 0)
			{
				//Mueve al Boss en función de si tiene que ir hacia arriba o hacia abajo
				switch (movBoss)
				{
				case enUP:
					contadorBoss++;
					finalBoss.sprite.Location.y -= 3;
					cont++;
					break;
				case enDOWN:
					contadorBoss--;
					cont++;
					finalBoss.sprite.Location.y += 3;
					break;
				}

				//Patrón de movimiento : Se mueve una vez hacia arriba, dos hacia abajo, y una hacia arriba, dispara el laser
				switch (contadorBoss)
				{
				case 1:
					movBoss = enemiMovement::enDOWN;
					break;
				case -1:
					movBoss = enemiMovement::enUP;
					break;

				}

				//Reinicia el CD para que tarde en hacer los movimientos
				CDBoss = cooldownAttacks;
			}
		}
	}
	
	//Cuando se hacen los 4 movimientos, se activa el laser
	if (cont == 4)
	{
		laser = true;
		cont = 0;
	}

	if (laser)
	{
		//Mientras CDlaser no llega a 0, se muestra en pantalla el disparo
		TimeMinus(CDlaser);

		if (CDlaser >= 0)
		{
			laserBoss.sprite.Location.x = -14;
			FASG::WriteSpriteBuffer(laserBoss.sprite.Location.x, laserBoss.sprite.Location.y, laserBoss.sprite);
		}
		else
		{
			//cuando llega a cero lo prepara todo para volver a mover al Boss
			movBoss = enemiMovement::enUP;
			CDBoss = cooldownAttacks;
			laserBoss.sprite.Location.x = -400;
			CDlaser = timeLaser;
			laser = false;
		}
	}
}

//Movimientos de los enemigos grandes durante la batalla final
void FinalBossMovementsLar()
{	
	//Se mueven indefinidamente como en el combate normal sin tiempo entre que se va y vuelve a aparecer
	if (CDLarOnLastStage > 0)
	{
		for (int i = 0; i < EnemiesLar; i++)
		{
			enemiesLarge[i].sprite.Location.x -= 2;

			if ((enemiesLarge[i].sprite.Location.x <= -22) && enemiesLarge[i].vida > 0)
			{
				TimeMinus(CDLarOnLastStage);
			}
		}
	}

	if (CDLarOnLastStage <= 0)
	{
		CDLarOnLastStage = coolDownOnLastStage;

		for (int a = 0; a < EnemiesLar; a++)
		{
			//Mientras sigan vivos se siguen volviendo a poner a la derecha de la pantalla
			if (enemiesLarge[a].vida > 0)
			{
				enemiesLarge[a].sprite.Location.x = 310;
			}
		}
	}
}



/*DISPAROS*/



//Disparos de los enemigos pequeños y medianos
void EnemiesShoots()
{
	for (int i = 0; i < EnemiesLit; i++)
	{
		//Inicializa el disparo en la posicion del enemigo, en caso de que pase el CD, pone la booleana en off para dejar que salga disparado
		if (shootEnemieLittle[i].onOff)
		{
			shootEnemieLittle[i].sprite.Location.x = enemiesLittle[i].sprite.Location.x - 3;
			shootEnemieLittle[i].sprite.Location.y = enemiesLittle[i].sprite.Location.y + 1;
			TimeMinus(shootEnemieLittle[i].CDShoot);

			if (shootEnemieLittle[i].CDShoot <= 0)
			{
				shootEnemieLittle[i].onOff = false;
			}
		}
		else
		{
			ShootEnemieLittle(i);
		}
	}

	for (int a = 0; a < EnemiesMed; a++)
	{
		//Inicializa el disparo en la posicion del enemigo, en caso de que pase el CD, pone la booleana en off para dejar que salga disparado
		if (shootEnemieMid[a].onOff)
		{
			shootEnemieMid[a].sprite.Location.x = enemiesMedium[a].sprite.Location.x - 3;
			shootEnemieMid[a].sprite.Location.y = enemiesMedium[a].sprite.Location.y + 1;
			TimeMinus(shootEnemieMid[a].CDShoot);

			if (shootEnemieMid[a].CDShoot <= 0)
			{
				shootEnemieMid[a].onOff = false;
			}
		}
		else
		{
			ShootEnemieMid(a);
		}
	}
}

//Disparos de los enemigos pequeños
void ShootEnemieLittle(int i)
{
	//Se mueven las balas independientemente la posición del enemigo
	shootEnemieLittle[i].sprite.Location.x -= shootEnemieLittle[i].shootEnemieSpeed * FASG::GetDeltaTime();

	if (shootEnemieLittle[i].sprite.Location.x <= -1)
	{
		//Se reinicializan en caso de salir de pantalla
		shootEnemieLittle[i].onOff = true;
		shootEnemieLittle[i].CDShoot = rand() % 5 + 1;
	}

	//Se dibujan los disparos
	FASG::WriteSpriteBuffer(shootEnemieLittle[i].sprite.Location.x, shootEnemieLittle[i].sprite.Location.y, shootEnemieLittle[i].sprite);
}

//Disparos de los enemigos medianos
void ShootEnemieMid(int i)
{
	//Se mueven las balas independientemente la posición del enemigo
	shootEnemieMid[i].sprite.Location.x -= shootEnemieMid[i].shootEnemieSpeed * FASG::GetDeltaTime();

	if (shootEnemieMid[i].sprite.Location.x <= -1)
	{
		//Se reinicializan en caso de salir de pantalla
		shootEnemieMid[i].onOff = true;
		shootEnemieMid[i].CDShoot = rand() % 5 + 3;
	}

	//Se dibujan los disparos
	FASG::WriteSpriteBuffer(shootEnemieMid[i].sprite.Location.x, shootEnemieMid[i].sprite.Location.y, shootEnemieMid[i].sprite);
}

//Reinicia el disparo del enemigo pequeño concreto
void RestartShootEnLit(int b)
{
	for (int i = 0; i < EnemiesLit; i++)
	{
		shootEnemieLittle[b].onOff = true;
		shootEnemieLittle[b].CDShoot = rand() % 3 + 1;
	}
}

//Reinicia el disparo del enemigo mediano concreto
void RestartShootEnMid(int a)
{
	for (int i = 0; i < EnemiesMed; i++)
	{
		shootEnemieMid[a].onOff = true;
		shootEnemieMid[a].CDShoot = rand() % 3 + 2;
	}
}



/*GETTERS - SETTERS*/



//Envia la cantidad de enemigos pequeños
int envLitEnQuantity()
{
	return EnemiesLit;
}

//Envia la cantidad de enemigos medianos
int envMidEnQuantity()
{
	return EnemiesMed;
}


//Envia la cantidad de enemigos grandes
int envLarEnQuantity()
{
	return EnemiesLar;
}


//Enemigo pequeño golpeado recibe daño
void ReciveLitDmg(int a, int dmg)
{
	enemiesLittle[a].vida -= dmg;
}

//Enemigo mediano golpeado recibe daño
void ReciveMidDmg(int b, int dmg)
{
	enemiesMedium[b].vida -= dmg;
}

//Enemigo grande golpeado recibe daño
void ReciveLarDmg(int c, int dmg)
{
	enemiesLarge[c].vida--;
}

//Boss recibe daño
void ReciveBossDmg(int dmg)
{
	finalBoss.vida-= dmg;
}