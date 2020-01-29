#pragma once
#include "FAriasSimpleGraphics.h"
enum SecPlayerMovement
{
	secRIGHT, secSTILL
};

//El segundo jugador
struct SecPlayer
{
	float speed;
	int life;
	FASG::Sprite spriteInMove;
	FASG::Sprite sprite;
};

//El disparo del segundo jugador
struct ShootSecP
{
	float speedSh;
	bool ShootOn;
	FASG::Sprite shootPlayer;
};

//Inicia el segundo jugador
void InitSecPlayer();

//Dibuja el segundo jugador
void DrawSecPlayer();

//Mueve al segundo jugador
void MovementSecPlayer();

//El disparo del segundo jugador
void ShootSecondPlayer();

//Reinicia el disparo del segundo jugador
void ShootSecOff();

//Para cuando recibe daño el segundo player
void ReciveSecPlayerDmg();