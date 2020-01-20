#include "Enemies.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

int const EnemiesLit = 4;

enemiMovement movEnemie = enemiMovement::enUP;

float const MovementCD = 0.2f;

float CD = MovementCD;

int contador=0;

TypeEnemieLittle enemiesLittle[EnemiesLit];

void InitEnemies()
{
	enemiesLittle[0].pos.Y = 16;
	enemiesLittle[1].pos.Y = 28;
	enemiesLittle[2].pos.Y = 40;
	enemiesLittle[3].pos.Y = 52;

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
				enemiesLittle[i].pos.Y-= 2;
				break;
			case enDOWN:
				enemiesLittle[i].pos.Y+= 2;
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
				enemiesLittle[i].pos.X-= 4;
			
			break;
		case 0:
			movEnemie = enemiMovement::enUP;

			for (int i = 0; i < EnemiesLit; i++)
			enemiesLittle[i].pos.X-=4;
			break;
		}

		CD = MovementCD;
	}

	for (int draw = 0; draw < EnemiesLit; draw++)
	{
		FASG::WriteSpriteBuffer(enemiesLittle[draw].pos.X, enemiesLittle[draw].pos.Y, enemiesLittle[draw].sprite);
	}
}