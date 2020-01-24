#include "GameOver.h"

extern Game game;

void GameOver()
{
	if (FASG::IsKeyPressed('C'))
	{
		game.login = true;
		game.gameOver = false;
	}

	if (FASG::IsKeyPressed('V'))
	{
		game.executable = false;
		game.login = false;
	}

	FASG::WriteSpriteBuffer(90, 5, FASG::Sprite("GameOver.txt"));

	FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "PULSA C PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(25, FASG::EAligned::CENTER, "PULSA V PARA CERRAR EL PROGRAMA", FASG::EForeColor::LightWhite);


}