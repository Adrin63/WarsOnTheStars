#include "LoginScreen.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

extern Game game;

bool on = true;

Logear logscrin;

float const DissapearCD = 1.f;

float culdown = DissapearCD;

void InitLogScreen()
{
	logscrin.dou.LoadSprite("LS.txt");
	logscrin.dou.Location.x = 97;
	logscrin.dou.Location.y = 5;
}


void LogScreen()
{	
	culdown -= FASG::GetDeltaTime();

	if (culdown <= 0)
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
		culdown = DissapearCD;
	}

	if (FASG::IsKeyPressed(' '))
	{
		game.executable = false;
		on = false;
	}

	FASG::WriteSpriteBuffer(logscrin.dou.Location.x, logscrin.dou.Location.y, logscrin.dou);

	if (on)
	{
		FASG::WriteStringBuffer(50, FASG::EAligned::CENTER, "Presione espacio para continuar", FASG::EForeColor::Yellow);
		FASG::WriteStringBuffer(54, FASG::EAligned::CENTER, "X para cerrar", FASG::EForeColor::Yellow);
	}

	

	
	if (FASG::IsKeyPressed ('X'))
	{
		game.executable = true;
		game.gameplay = true;
		game.login = true;
	}	
}