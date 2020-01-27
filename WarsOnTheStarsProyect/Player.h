#pragma once
#include "FAriasSimpleGraphics.h"

//Posiciones de movimiento del jugador
enum PlayerMovement
{
	RIGHT, STILL
};

enum ShootType
{
	SHOOT, MISIL
};

//El propio jugador
struct Player
{
	float speed= 90.f;
	int life;
	FASG::Sprite spriteInMove;
	FASG::Sprite sprite;
};

struct ShootP
{
	ShootType type;
	float speedSh;
	bool ShootOn;
	FASG::Sprite shootPlayer;
};

//Inicia el jugador
void InitPlayer();

//Dibuja el jugador
void DrawPlayer();

//Movimiento del jugador
void MovementPlayer();

//Disparo del jugador
void ShootPlayer(ShootType a, bool b);

//Resetea disparo en caso de golpear a enemigo
void ShootOff(bool a, ShootType b);

//Recibe daño el jugador, y en función si te da el enemigo grande o no te hace 1 o 2 de daño
void RecivePlayerDmg(bool dmg);