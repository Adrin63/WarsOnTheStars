#include "End.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"	

extern Game game;

bool onDead = true;

float const DissapearCDDead = 1.f;

float coolDownDead = DissapearCDDead;

void GameOver()
{
	TimeMinus(coolDownDead);

	if (coolDownDead <= 0)
	{
		switch (onDead)
		{
		case true:
			onDead = false;
			break;
		case false:
			onDead = true;
			break;
		}
		coolDownDead = DissapearCDDead;
	}

	if (FASG::IsKeyPressed('C'))
	{
		game.login = true;
		game.end = false;
	}

	if (onDead)
	{
		FASG::WriteSpriteBuffer(90, 10, FASG::Sprite("GameOver.txt"));
		FASG::WriteStringBuffer(30, FASG::EAligned::CENTER, "PULSA C PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);
	}
}
