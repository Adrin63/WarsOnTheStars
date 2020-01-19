#include "Enemies.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

int const EnemiesLit = 4;

enemiMovement movEnemie = enemiMovement::enUP;

float const MovementCD = 1.f;

float CD = MovementCD;

int contador=0;

TypeEnemieLittle enemiesLittle[EnemiesLit];

void InitEnemies()
{
	enemiesLittle[0].pos.Y = 12;
	enemiesLittle[1].pos.Y = 24;
	enemiesLittle[2].pos.Y = 36;
	enemiesLittle[3].pos.Y = 48;

	for (int i = 0; i < EnemiesLit; i++)
	{
		enemiesLittle[i].pos.X = 200;
	}
}

void DrawEnemies()
{
	CD -= FASG::GetDeltaTime();

	if (CD <= 0)
	{
		for (int i = 0; i < EnemiesLit; i++)
		{
			switch (movEnemie)
			{
			case enUP:
				enemiesLittle[i].pos.Y--;
				break;
			case enDOWN:
				enemiesLittle[i].pos.Y++;
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
		case 5:
			movEnemie = enemiMovement::enDOWN;
			break;
		case 0:
			movEnemie = enemiMovement::enUP;
			break;
		}

		CD = MovementCD;
	}

	for (int draw = 0; draw < EnemiesLit; draw++)
	{
		FASG::WriteSpriteBuffer(enemiesLittle[draw].pos.X, enemiesLittle[draw].pos.Y, enemiesLittle[draw].sprite);
	}
}