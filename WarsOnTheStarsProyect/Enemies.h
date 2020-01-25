#pragma once
#include "Engine.h"
#include "FAriasSimpleGraphics.h"

enum enemiMovement
{
	enDOWN, enUP
};

enum enemiBoss
{
	LASER, DISPARO
};

struct Enemie
{
	FASG::Sprite sprite;
	int vida;
};

struct Laser
{
	FASG::Sprite sprite;
};

struct Shoot
{
	bool onOff;
	float CDShoot;
	FASG::Sprite sprite;
	float shootEnemieSpeed;
};

void InitEnemies();
void DrawEnemies();

void MovementLittle();
void MovementMiddle();
void MovementLarge();

void AllLeftLarg();
void FromRightLarg(bool a);

void FinalStagePreparation();
void FinalBossMovements();

int envLitEnQuantity();
int envMidEnQuantity();
int envLarEnQuantity();

void ReciveLitDmg(int a);
void ReciveMidDmg(int b);
void ReciveLarDmg(int c);
void ReciveBossDmg();

void EnemiesShoots();
void ShootEnemieLittle(int i);
void ShootEnemieMid(int i);

void FinalBossMovementsLar();

void RestartShootEnLit(int b);
void RestartShootEnMid(int a);