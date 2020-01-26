#include "FAriasSimpleGraphics.h"
#include "Victoria.h"
#include "Engine.h"

extern Game game;

void Win()
{
	FASG::WriteSpriteBuffer(100, 5, FASG::Sprite("Victoria.txt"));

	FASG::WriteStringBuffer(52, FASG::EAligned::CENTER, "PULSA X PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);

	FASG::RenderFrame();

	if (FASG::IsKeyPressed('X'))
	{
		game.win = false;
		game.executable = true;
	}

}
