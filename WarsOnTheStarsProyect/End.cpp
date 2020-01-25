#include "End.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"	

extern Game game;

void GameOver()
{
	if (FASG::IsKeyPressed('C'))
	{
		game.login = true;
		game.end = false;
	}

	FASG::WriteSpriteBuffer(90, 5, FASG::Sprite("GameOver.txt"));

	FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "PULSA C PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);
}
