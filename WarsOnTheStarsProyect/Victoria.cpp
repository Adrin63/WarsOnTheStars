#include "Victoria.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

extern Game game;

void Victory()
{
	if (FASG::IsKeyPressed('X'))
	{

	}

	FASG::WriteSpriteBuffer(100, 5, FASG::Sprite("Victoria.txt"));

	FASG::WriteStringBuffer(52, FASG::EAligned::CENTER, "PULSA X PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);
}