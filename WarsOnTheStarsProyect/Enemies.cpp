#include "Enemies.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

int const EnemiesLit = 4;
int const EnemiesMed = 3;
int const EnemiesLar = 2;

enemiMovement movEnemie = enemiMovement::enUP;

float const MovementCD = 0.1f;

float CD = MovementCD;

int contador=0;

TypeEnemieLittle enemiesLittle[EnemiesLit];
TypeEnemieLittle enemiesMedium[EnemiesMed];
TypeEnemieLittle enemiesLarge[EnemiesLar];

void InitEnemies()
{
	
	enemiesLittle[0].sprite.Location.y = 10;
	enemiesLittle[1].sprite.Location.y = 22;
	enemiesLittle[2].sprite.Location.y = 34;
	enemiesLittle[3].sprite.Location.y = 46;

	for (int i = 0; i < EnemiesLit; i++)
	{
		enemiesLittle[i].sprite.LoadSprite("EnemieLittle.txt");
		enemiesLittle[i].sprite.Location.x = 200;
	}

	enemiesMedium[0].sprite.Location.y = 7;
	enemiesMedium[1].sprite.Location.y = 26;
	enemiesMedium[2].sprite.Location.y = 45;

	for (int l = 0; l < EnemiesMed; l++)
	{
		enemiesMedium[l].sprite.LoadSprite("EnemieMedium.txt");
		enemiesMedium[l].sprite.Location.x = 225;
	}

	enemiesLarge[0].sprite.Location.y = 3;
	enemiesLarge[1].sprite.Location.y = 41;

	for (int j = 0; j < EnemiesMed; j++)
	{
		enemiesLarge[j].sprite.LoadSprite("EnemieLarge.txt");
		enemiesLarge[j].sprite.Location.x = 260;
	}
}

void DrawEnemies()
{
	CD -= FASG::GetDeltaTime();

	/*if (CD <= 0)
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

		CD = MovementCD;
	}*/

	for (int draw = 0; draw < EnemiesLit; draw++)
	{
		FASG::WriteSpriteBuffer(enemiesLittle[draw].sprite.Location.x, enemiesLittle[draw].sprite.Location.y, enemiesLittle[draw].sprite);
	}

	for (int draw = 0; draw < EnemiesMed; draw++)
	{
		FASG::WriteSpriteBuffer(enemiesMedium[draw].sprite.Location.x, enemiesMedium[draw].sprite.Location.y, enemiesMedium[draw].sprite);
	}

	for (int draw = 0; draw < EnemiesLar; draw++)
	{
		FASG::WriteSpriteBuffer(enemiesLarge[draw].sprite.Location.x, enemiesLarge[draw].sprite.Location.y, enemiesLarge[draw].sprite);
	}
}