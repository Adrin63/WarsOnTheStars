#include "LoginScreen.h"
#include "FAriasSimpleGraphics.h"
#include "Engine.h"

//Variables de game para determinar el punto donde estas del juego
extern Game game;

Logear logscreen;

//Hacer que aparezcan y desaparezcan las letras en pantalla
bool on = true;
float const DissapearCD = 1.f;
float coolDown = DissapearCD;

//Inicializar la Pantalla de Inicio
void InitLogScreen()
{
	logscreen.log.LoadSprite("LS.txt");
	logscreen.log.Location.x = 97;
	logscreen.log.Location.y = 5;
}

void LogScreen()
{	
	if (on)
	{
		FASG::WriteStringBuffer(50, FASG::EAligned::CENTER, "PRESIONE ESPACIO PARA CONTINUAR", FASG::EForeColor::Yellow);
		FASG::WriteStringBuffer(54, FASG::EAligned::CENTER, "X PARA SALIR", FASG::EForeColor::Yellow);
	}

	//Hacer que aparezcan y desaparezcan las letras en pantalla
	TimeMinus(coolDown);

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



	FASG::WriteSpriteBuffer(logscreen.log.Location.x, logscreen.log.Location.y, logscreen.log);
	FASG::RenderFrame();



	//Salir de la consola
	if (FASG::IsKeyPressed('X'))
	{
		game.login = false;
	}

	
	//Entrar al menu
	if (FASG::IsKeyPressed(' '))
	{
		game.executable = true;
		on = false;
	}
}