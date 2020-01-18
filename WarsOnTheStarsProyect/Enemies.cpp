#include "Enemies.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

int const EnemiesLit = 3;

TypeEnemieLittle enemiesLittle[EnemiesLit];


void InitEnemies()
{
	enemiesLittle[0].pos.Y = 15;
	enemiesLittle[1].pos.Y = 30;
	enemiesLittle[2].pos.Y = 45;

	for (int i = 0; i < EnemiesLit; i++)
	{
		enemiesLittle[i].pos.X = 200;
	}
}

void DrawEnemies()
{
	for (int draw = 0; draw < EnemiesLit; draw++)
	{
		FASG::WriteSpriteBuffer(enemiesLittle[draw].pos.X, enemiesLittle[draw].pos.Y, enemiesLittle[draw].sprite);
	}
}