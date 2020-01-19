#include "LoginScreen.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

extern Game game;

bool on = true;

//Logear logscrin;

float const DissapearCD = 1.f;

float culdown = DissapearCD;

//void InitLogScreen()
//{
//	logscrin.pos.X = 97;
//	logscrin.pos.Y = 5;
//}

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

	if (on)
	{
		FASG::WriteStringBuffer(50, FASG::EAligned::CENTER, "Presione espacio para continuar", FASG::EForeColor::Yellow);
		FASG::WriteStringBuffer(54, FASG::EAligned::CENTER, "X para cerrar", FASG::EForeColor::Yellow);
	}

	//FASG::WriteSpriteBuffer(logscrin.pos.X, logscrin.pos.Y, logscrin.dou);

	if (FASG::IsKeyPressed(' '))
	{
		game.executable = false;
		game.gameplay = false;
		on = true;
	}
	if (FASG::IsKeyPressed ('X'))
	{
		game.executable = true;
		game.gameplay = true;
		game.login = true;
	}	
}