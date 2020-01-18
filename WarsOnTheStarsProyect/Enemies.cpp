#include "Enemies.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

Enemie en;

extern Game game;

void InitEnemies()
{
	en.pos.Y = 10.f;
	en.pos.X = game.W = 0.8f;
}

void DrawEnemies()
{
	FASG::WriteSpriteBuffer(en.pos.X, en.pos.Y, en.spriteEn);
}