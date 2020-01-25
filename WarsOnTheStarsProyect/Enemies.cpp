#include "Enemies.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

int const EnemiesLit = 4;
int const EnemiesMed = 3;
int const EnemiesLar = 2;

enemiMovement movEnemie = enemiMovement::enUP, movBoss;

extern Game game;

enemiBoss currentAttack;

Shoot shootEnemieLittle[EnemiesLit], shootEnemieMid[EnemiesMed];

float const MovementCDLittle = 0.85f, MovementCDMedium = 1.25f, MovementCDLarge = 3.f;

float CDLittle = MovementCDLittle, CDMedium = MovementCDMedium, CDLarge = MovementCDLarge;

float CDUntilFinalStage = 8.2f;
float CDStartFinalStage = 8.f;
float timeUntilAppear = 2.f;
float CDUntilAppear = timeUntilAppear;

int contador = 0, contadorBoss = 0;

float const cooldownAttacks = 2.f;
float CDBoss = cooldownAttacks;

bool badTime = false, laser = false;
bool RestartLarge[EnemiesLar];

bool finalStageStart = false, finalStageLar = false, allAway = false, start = true, startAttackFinalBoss = false;;

int DeadLit = 0, DeadMid = 0, DeadLar = 0;

bool allDeadLit = false, allDeadMid = false, allDeadLar = false;

Enemie enemiesLittle[EnemiesLit], enemiesMedium[EnemiesMed], enemiesLarge[EnemiesLar], finalBoss;

float const coolDownOnLastStage = 1.f;
float CDLarOnLastStage = coolDownOnLastStage;

int attack = 0;
float const timeLaser = 2.5f;
float CDlaser = timeLaser;
int cont = 0;

Laser laserBoss;

FASG::WAVESound finalBossSong;

void InitEnemies()
{
	finalBossSong.LoadSound("BadTime.wav");

	allAway = false;
	DeadLit = 0, DeadMid = 0, DeadLar = 0;
	allDeadLit = false, allDeadMid = false, allDeadLar = false;
	finalStageStart = false;
	finalStageLar = false;
	start = true;
	startAttackFinalBoss = false;
	CDUntilFinalStage = 7.9f;
	CDStartFinalStage = 5.0f;

	badTime = false;
	contadorBoss = 0;
	CDLittle = MovementCDLittle;
	CDMedium = MovementCDMedium;
	CDUntilAppear = timeUntilAppear;
	CDLarge = MovementCDLarge;


	cont = 0;
	laser = false;
	laserBoss.sprite.LoadSprite("EnemieLaser.txt");
	laserBoss.sprite.Location.x = -14;
	laserBoss.sprite.Location.y = 27;


	enemiesLittle[0].sprite.Location.y = 10;
	enemiesLittle[1].sprite.Location.y = 22;
	enemiesLittle[2].sprite.Location.y = 34;
	enemiesLittle[3].sprite.Location.y = 46;

	for (int i = 0; i < EnemiesLit; i++)
	{
		enemiesLittle[i].vida = 5;
		enemiesLittle[i].sprite.LoadSprite("EnemieLittle.txt");
		FASG::Sprite::AddToCollisionSystem(enemiesLittle[i].sprite, "enLit" + i);
		enemiesLittle[i].sprite.Location.x = 200;

		shootEnemieLittle[i].sprite.LoadSprite("ShootEnemieLit.txt");
		shootEnemieLittle[i].onOff = true;
		shootEnemieLittle[i].CDShoot = rand() % 5 + 1;
		shootEnemieLittle[i].shootEnemieSpeed = 60.f;
		FASG::Sprite::AddToCollisionSystem(shootEnemieLittle[i].sprite, "ShootEnemieLit" + i);
	}

	enemiesMedium[0].sprite.Location.y = 7;
	enemiesMedium[1].sprite.Location.y = 26;
	enemiesMedium[2].sprite.Location.y = 45;

	for (int l = 0; l < EnemiesMed; l++)
	{
		enemiesMedium[l].vida = 15;
		enemiesMedium[l].sprite.LoadSprite("EnemieMedium.txt");
		FASG::Sprite::AddToCollisionSystem(enemiesMedium[l].sprite, "enMed" + l);
		enemiesMedium[l].sprite.Location.x = 225;

		shootEnemieMid[l].sprite.LoadSprite("ShootEnemieMid.txt");
		shootEnemieMid[l].onOff = true;
		shootEnemieMid[l].CDShoot = rand() % 5 + 3;
		shootEnemieMid[l].shootEnemieSpeed = 20.f;
		FASG::Sprite::AddToCollisionSystem(shootEnemieMid[l].sprite, "ShootEnemieMid" + l);
	}

	enemiesLarge[0].sprite.Location.y = 3;
	enemiesLarge[1].sprite.Location.y = 41;

	for (int j = 0; j < EnemiesLar; j++)
	{
		enemiesLarge[j].sprite.LoadSprite("EnemieLarge.txt");
		FASG::Sprite::AddToCollisionSystem(enemiesLarge[j].sprite, "enLarge" + j);
		enemiesLarge[j].sprite.Location.x = 260;
	}

	finalBoss.sprite.LoadSprite("FinalBoss.txt");
	FASG::Sprite::AddToCollisionSystem(finalBoss.sprite, "FinalBoss");
	finalBoss.sprite.Location.y = 22;
	finalBoss.sprite.Location.x = 305;

}

void DrawEnemies()
{
	TimeMinus(CDLittle);
	TimeMinus(CDMedium);
	TimeMinus(CDLarge);

	EnemiesShoots();

	MovementLittle();

	MovementMiddle();

	if (!(allDeadLit && allDeadMid))
	{
		MovementLarge();
	}

	if (badTime)
	{
		finalBossSong.Play();
	}

	if ((allDeadLit && allDeadMid) && (!finalStageStart))
	{
		FinalStagePreparation();
	}

	if (finalStageStart)
	{
		TimeMinus(CDStartFinalStage);

		if (CDStartFinalStage <= 0)
		{
			FinalBossMovements();
			FinalBossMovementsLar();
		}
	}

	for (int draw = 0; draw < EnemiesLar; draw++)
	{
		if (!game.end)
		{
			FASG::WriteSpriteBuffer(enemiesLarge[draw].sprite.Location.x, enemiesLarge[draw].sprite.Location.y, enemiesLarge[draw].sprite);
		}
	}

	if (!game.end)
	FASG::WriteSpriteBuffer(finalBoss.sprite.Location.x, finalBoss.sprite.Location.y,finalBoss.sprite);
}

void EnemiesShoots()
{
	for (int i = 0; i < EnemiesLit; i++)
	{
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

void ShootEnemieLittle(int i)
{
	shootEnemieLittle[i].sprite.Location.x -= shootEnemieLittle[i].shootEnemieSpeed * FASG::GetDeltaTime();

	if (shootEnemieLittle[i].sprite.Location.x <= -1)
	{
		shootEnemieLittle[i].onOff = true;
		shootEnemieLittle[i].CDShoot = rand() % 5 + 1;
	}

	FASG::WriteSpriteBuffer(shootEnemieLittle[i].sprite.Location.x, shootEnemieLittle[i].sprite.Location.y, shootEnemieLittle[i].sprite);
}

void ShootEnemieMid(int i)
{
	shootEnemieMid[i].sprite.Location.x -= shootEnemieMid[i].shootEnemieSpeed * FASG::GetDeltaTime();

	if (shootEnemieMid[i].sprite.Location.x <= -1)
	{
		shootEnemieMid[i].onOff = true;
		shootEnemieMid[i].CDShoot = rand() % 5 + 3;
	}

	FASG::WriteSpriteBuffer(shootEnemieMid[i].sprite.Location.x, shootEnemieMid[i].sprite.Location.y, shootEnemieMid[i].sprite);
}

void MovementLittle()
{
	if (CDLittle <= 0)
	{
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

	if (DeadLit >= EnemiesLit)
	{
		allDeadLit = true;
	}
}

void MovementMiddle()
{
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

	if (DeadMid == EnemiesMed)
	{
		allDeadMid = true;
	}
}

void MovementLarge()
{
	if (!allAway)
	{
		if (CDLarge <= 0)
		{
			for (int i = 0; i < EnemiesLar; i++)
			{
				enemiesLarge[i].sprite.Location.x -= 2;

				if (enemiesLarge[i].sprite.Location.x <= -22)
				{
					RestartLarge[i] = true;
					allAway = true;
				}
			}			
		}
	}

	if (allAway)
	{
		TimeMinus(CDUntilAppear);

		if (CDUntilAppear <= 0)
		{
			FromRightLarg(true);
		}
	}
}

void FinalStagePreparation()
{
	for (int j = 0; j < EnemiesLar; j++)
	{
		enemiesLarge[j].vida = 30;
	}
	
	if (CDUntilFinalStage > 0)
	{
		AllLeftLarg();
	}
	
	if (CDUntilFinalStage <= 0)
	{
		FromRightLarg(false);
	}
}

void FinalBossMovements()
{
	if (!laser)
	{
		if (!startAttackFinalBoss)
		{
			//CAMBIAR A 4
			attack = rand() % 1;
			movBoss = enemiMovement::enUP;
		}

		if (start)
		{
			finalBoss.sprite.Location.x -= 0.4;
			if (finalBoss.sprite.Location.x <= 240)
				start = false;
		}
		else
		{
			TimeMinus(CDBoss);
			startAttackFinalBoss = true;

			if (CDBoss <= 0)
			{
				switch (attack)
				{
				case 0:
					currentAttack = enemiBoss::LASER;
					CDBoss += 0.25f;
					break;
				default:
					currentAttack = enemiBoss::DISPARO;
				}

				switch (currentAttack)
				{
				case LASER:

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

					switch (contadorBoss)
					{
					case 1:
						movBoss = enemiMovement::enDOWN;
						
						break;
					case -1:
						movBoss = enemiMovement::enUP;
						
						break;
					}
				case DISPARO:
					break;
				}
			}
		}
	}

	if (cont == 4)
	{
		laser = true;
		cont = 0;
	}

	if (laser)
	{
		TimeMinus(CDlaser);
		if (CDlaser >= 0)
		{
			FASG::WriteSpriteBuffer(laserBoss.sprite.Location.x, laserBoss.sprite.Location.y, laserBoss.sprite);
		}
		else
		{
			CDBoss = cooldownAttacks;
			CDlaser = timeLaser;
			laser = false;
			startAttackFinalBoss = false;
		}
	}
}

void FinalBossMovementsLar()
{
	if (CDLarOnLastStage <= 0)
	{
		CDLarOnLastStage = coolDownOnLastStage;
		for (int a = 0; a < EnemiesLar; a++)
		{
			enemiesLarge[a].sprite.Location.x = 310;
		}
	}
	if (CDLarOnLastStage > 0)
	{
		for (int i = 0; i < EnemiesLar; i++)
		{
			enemiesLarge[i].sprite.Location.x -= 2;

			if (enemiesLarge[i].sprite.Location.x <= -22)
			{
				TimeMinus(CDLarOnLastStage);
			}
		}
	}
}

void AllLeftLarg()
{
	int cont = 0;
	for (int i = 0; i < EnemiesLar; i++)
	{
		enemiesLarge[i].sprite.Location.x -= 2;

		if (enemiesLarge[i].sprite.Location.x <= -22)
		{
			cont++;
		}
	}
	if (cont == 2)
	{
		badTime = true;
		TimeMinus(CDUntilFinalStage);
	}
}

void FromRightLarg(bool a)
{
	for (int i = 0; i < EnemiesLar; i++)
	{
		if (RestartLarge[i])
		{
			enemiesLarge[i].sprite.Location.x = 305;
			RestartLarge[i] = false;
		}

		switch (a)
		{
		case true:
			enemiesLarge[i].sprite.Location.x--;
			break;
		case false:
			enemiesLarge[i].sprite.Location.x -= 0.4f;
			break;
		}
		
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

void RestartShootEnLit(int b)
{
	for (int i = 0; i < EnemiesLit; i++)
	{
		shootEnemieLittle[b].onOff = true;
		shootEnemieLittle[b].CDShoot = rand() % 5 + 1;
	}
}

void RestartShootEnMid(int a)
{
	for (int i = 0; i < EnemiesMed; i++)
	{
		shootEnemieMid[a].onOff = true;
		shootEnemieMid[a].CDShoot = rand() % 5 + 3;
	}
}


//Getters - Setters
int envLitEnQuantity()
{
	return EnemiesLit;
}

int envMidEnQuantity()
{
	return EnemiesMed;
}

int envLarEnQuantity()
{
	return EnemiesLar;
}

void ReciveLitDmg(int a)
{
	enemiesLittle[a].vida--;
}

void ReciveMidDmg(int b)
{
	enemiesMedium[b].vida--;
}

void ReciveLarDmg(int c)
{
	enemiesLarge[c].vida--;
}