#include "FAriasSimpleGraphics.h"
#include "Victoria.h"
#include "Engine.h"

extern Game game;

void Win()
{
	if (FASG::IsKeyPressed('X'))
	{
		game.win = false;
	}

	FASG::WriteSpriteBuffer(100, 5, FASG::Sprite("Victoria.txt"));

	FASG::WriteStringBuffer(52, FASG::EAligned::CENTER, "PULSA X PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);
}
