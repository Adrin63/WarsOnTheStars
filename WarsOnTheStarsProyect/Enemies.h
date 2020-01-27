#pragma once
#include "Engine.h"
#include "FAriasSimpleGraphics.h"

//Enum que indica si el enemigo esta llendo hacia arriba o hacia abajo
enum enemiMovement
{
	enDOWN, enUP
};

//Struct para los enemigos, tanto peque�os, medianos y grandes
struct Enemie
{
	FASG::Sprite sprite;
	int vida;
};

//Struct para el Laser, ataque del Boss
struct Laser
{
	FASG::Sprite sprite;
};

//Struct para los disparos de los enemigos
struct ShootE
{
	bool onOff;
	float CDShoot;
	FASG::Sprite sprite;
	float shootEnemieSpeed;
};

//Inicializaci�n de los Enemigos
void InitEnemies();

//Juego
void DrawEnemies();


/*MOVIMIENTO DE LOS ENEMIGOS*/


//Movimiento de los enemigos peque�os
void MovementLittle();

//Movimiento de los enemigos medianos
void MovementMiddle();

//Movimiento de los enemigos grandes
void MovementLarge();

/*Coloca a los enemigos grandes a la derecha, fuera de la pantalla, los pone en 260
y en funci�n si es el combate normal o la preparaci�n del combate final, va mas rapido o mas lento*/
void FromRightLarg(bool a);


/*PREPARACI�N DEL COMBATE FINAL*/

//Preparaci�n del combate final
void FinalStagePreparation();

//Movimiento de los enemigos grandes para iniciar la preparaci�n de la fase final
void AllLeftLarg();


/*COMBATE FINAL*/

//Movimientos del enemigo final
void FinalBossMovements();

//Movimientos de los enemigos grandes durante la batalla final
void FinalBossMovementsLar();


/*DISPAROS*/

//Disparos de los enemigos peque�os y medianos
void EnemiesShoots();

//Disparos de los enemigos peque�os
void ShootEnemieLittle(int i);

//Disparos de los enemigos medianos
void ShootEnemieMid(int i);

//Reinicia el disparo del enemigo peque�o concreto
void RestartShootEnLit(int b);

//Reinicia el disparo del enemigo mediano concreto
void RestartShootEnMid(int a);


/*GETTERS - SETTERS*/

//Envia la cantidad de enemigos peque�os
int envLitEnQuantity();

//Envia la cantidad de enemigos medianos
int envMidEnQuantity();

//Envia la cantidad de enemigos grandes
int envLarEnQuantity();


//Enemigo peque�o golpeado recibe da�o
void ReciveLitDmg(int a, int dmg);

//Enemigo mediano golpeado recibe da�o
void ReciveMidDmg(int b, int dmg);

//Enemigo grande golpeado recibe da�o
void ReciveLarDmg(int c, int dmg);

//Boss recibe da�o
void ReciveBossDmg(int dmg);