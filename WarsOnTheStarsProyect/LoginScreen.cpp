#include "LoginScreen.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

extern Game game;

bool on = true;

Logear logscreen;

float const DissapearCD = 1.f;

float coolDown = DissapearCD;

void InitLogScreen()
{
	logscreen.log.LoadSprite("LS.txt");
	logscreen.log.Location.x = 97;
	logscreen.log.Location.y = 5;
}

void LogScreen()
{	
	coolDown -= FASG::GetDeltaTime();

	if (coolDown <= 0)
	{
		switch (on)
		{
		case true:
			on = false;
			break;
		case false:
			on = true;
			break;
		}
		coolDown = DissapearCD;
	}

	if (FASG::IsKeyPressed(' '))
	{
		game.executable = true; 
		game.gameplay = false;
		game.difficulty = false;
		game.glossary = false;
		game.howToPlay = false;
		game.gameOver = false;
		on = false;
	}

	FASG::WriteSpriteBuffer(logscreen.log.Location.x, logscreen.log.Location.y, logscreen.log);

	if (on)
	{
		FASG::WriteStringBuffer(50, FASG::EAligned::CENTER, "PRESIONE ESPACIO PARA CONTINUAR", FASG::EForeColor::Yellow);
		FASG::WriteStringBuffer(54, FASG::EAligned::CENTER, "X PARA SALIR", FASG::EForeColor::Yellow);
	}

	if (FASG::IsKeyPressed ('X'))
	{
		game.login = false;
	}	
}