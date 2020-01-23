#include "Enemies.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

int const EnemiesLit = 4;
int const EnemiesMed = 3;
int const EnemiesLar = 2;

enemiMovement movEnemie = enemiMovement::enUP;

float const MovementCDLittle = 0.85f, MovementCDMedium = 1.25f, MovementCDLarge = 3.f;

float CDLittle = MovementCDLittle, CDMedium = MovementCDMedium, CDLarge = MovementCDLarge;

float timeUntilAppear = 2.f;
float CDUntilAppear = timeUntilAppear;

int contador = 0;

bool RestartLarge[EnemiesLar];

bool allAway = false;

TypeEnemieLittle enemiesLittle[EnemiesLit];

TypeEnemieMedium enemiesMedium[EnemiesMed];

TypeEnemieLarge enemiesLarge[EnemiesLar];

void InitEnemies()
{
	
	enemiesLittle[0].sprite.Location.y = 10;
	enemiesLittle[1].sprite.Location.y = 22;
	enemiesLittle[2].sprite.Location.y = 34;
	enemiesLittle[3].sprite.Location.y = 46;

	for (int i = 0; i < EnemiesLit; i++)
	{
		enemiesLittle[i].sprite.LoadSprite("EnemieLittle.txt");
		FASG::Sprite::AddToCollisionSystem(enemiesLittle[i].sprite, "enLit" + i);
		enemiesLittle[i].sprite.Location.x = 200;
	}

	enemiesMedium[0].sprite.Location.y = 7;
	enemiesMedium[1].sprite.Location.y = 26;
	enemiesMedium[2].sprite.Location.y = 45;

	for (int l = 0; l < EnemiesMed; l++)
	{
		enemiesMedium[l].sprite.LoadSprite("EnemieMedium.txt");
		FASG::Sprite::AddToCollisionSystem(enemiesMedium[l].sprite, "enMed" + l);
		enemiesMedium[l].sprite.Location.x = 225;
	}

	enemiesLarge[0].sprite.Location.y = 3;
	enemiesLarge[1].sprite.Location.y = 41;

	for (int j = 0; j < EnemiesLar; j++)
	{
		enemiesLarge[j].sprite.LoadSprite("EnemieLarge.txt");
		FASG::Sprite::AddToCollisionSystem(enemiesMedium[j].sprite, "enLar" + j);
		enemiesLarge[j].sprite.Location.x = 260;
	}
}

void DrawEnemies()
{
	CDLittle -= FASG::GetDeltaTime();
	CDMedium -= FASG::GetDeltaTime();
	CDLarge -= FASG::GetDeltaTime();

	MovementLittle();
	
	MovementMiddle();

	MovementLarge();

	for (int draw = 0; draw < EnemiesLit; draw++)
	{
		if (enemiesLittle[draw].vida > 0)
			FASG::WriteSpriteBuffer(enemiesLittle[draw].sprite.Location.x, enemiesLittle[draw].sprite.Location.y, enemiesLittle[draw].sprite);
	}

	for (int draw = 0; draw < EnemiesMed; draw++)
	{
		if (enemiesMedium[draw].vida > 0)
			FASG::WriteSpriteBuffer(enemiesMedium[draw].sprite.Location.x, enemiesMedium[draw].sprite.Location.y, enemiesMedium[draw].sprite);
	}

	for (int draw = 0; draw < EnemiesLar; draw++)
	{
		if (enemiesLarge[draw].vida > 0)
			FASG::WriteSpriteBuffer(enemiesLarge[draw].sprite.Location.x, enemiesLarge[draw].sprite.Location.y, enemiesLarge[draw].sprite);
	}
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
		CDUntilAppear -= FASG::GetDeltaTime();

		if (CDUntilAppear <= 0)
		{
			for (int i = 0; i < EnemiesLar; i++)
			{
				if (RestartLarge[i])
				{
					enemiesLarge[i].sprite.Location.x = 308;
					RestartLarge[i] = false;
				}

				enemiesLarge[i].sprite.Location.x--;

				if (enemiesLarge[i].sprite.Location.x <= 260)
				{
					enemiesLarge[i].sprite.Location.x = 260;
					CDUntilAppear = timeUntilAppear;
					CDLarge = MovementCDLarge;
					RestartLarge[i] = true;
					allAway = false;
				}
			}
		}
	}
}

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

void ReciveLitDmg(int i)
{
	enemiesLittle[i].vida--;
}