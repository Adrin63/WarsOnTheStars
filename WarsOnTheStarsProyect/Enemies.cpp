#include "Enemies.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

int const EnemiesLit = 4;

enemiMovement movEnemie = enemiMovement::enUP;

float const MovementCD = 0.1f;

float CD = MovementCD;

int contador=0;

TypeEnemieLittle enemiesLittle[EnemiesLit];

void InitEnemies()
{
	
	enemiesLittle[0].sprite.Location.y = 16;
	enemiesLittle[1].sprite.Location.y = 28;
	enemiesLittle[2].sprite.Location.y = 40;
	enemiesLittle[3].sprite.Location.y = 52;

	for (int i = 0; i < EnemiesLit; i++)
	{
		enemiesLittle[i].sprite.LoadSprite("EnemieLittle.txt");
		enemiesLittle[i].sprite.Location.x = 200;
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
	}

	for (int draw = 0; draw < EnemiesLit; draw++)
	{
		FASG::WriteSpriteBuffer(enemiesLittle[draw].sprite.Location.x, enemiesLittle[draw].sprite.Location.y, enemiesLittle[draw].sprite);
	}
}